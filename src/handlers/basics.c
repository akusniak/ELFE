#include "../../includes/elfe.h"

void handle_basic(ElfData *elf_data) {
    struct stat fileStat;
    if (stat(elf_data->file_path, &fileStat) < 0) {
        perror("Failed to get file stats");
        return;
    }

    struct passwd pwd;
    struct passwd *result;
    char *buf;
    size_t bufsize;
    bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    if ((int)bufsize == -1) {          /* Value was indeterminate */
        bufsize = 16384;        /* Should be more than enough */
    }

    buf = malloc(bufsize);
    if (buf == NULL) {
        perror("Malloc failed");
        return;
    }

    if (getpwuid_r(fileStat.st_uid, &pwd, buf, bufsize, &result) != 0 || result == NULL) {
        perror("Failed to get username");
        free(buf);
        return;
    }

    printf("\n*********************************\n\nInformation for %s\nSize of file: %ld bytes\nOwner uid: %d, Name: %s\nPermissions: %o (octal)\nAllocated blocks: %ld\nSize of each block: %ld bytes\nInode number: %ld\n*********************************\n",
             elf_data->file_path,
             fileStat.st_size,
             fileStat.st_uid, pwd.pw_name,
             fileStat.st_mode & 0777,
             fileStat.st_blocks,
             fileStat.st_blksize,
             fileStat.st_ino);

    free(buf);
}

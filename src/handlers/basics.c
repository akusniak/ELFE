#include "../../includes/elfe.h"

/**
 * Function to handle basic information display for an ELF file.
 * This function prints basic information about the ELF file, such as its size,
 * owner, permissions, allocated blocks, block size, and inode number.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_basic(ElfData *elf_data) {
    struct stat fileStat;
    // Get file statistics
    if (stat(elf_data->file_path, &fileStat) < 0) {
        perror("Failed to get file stats");
        return;
    }

    struct passwd pwd;
    struct passwd *result;
    char *buf;
    size_t bufsize;
    bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    if ((int)bufsize == -1) {
        bufsize = 16384;
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

    // Print basic file information
    printf("\n*********************************\n");
    printf("Information for: %s\n", elf_data->file_path);
    printf("Size of file: %ld bytes\n", fileStat.st_size);
    printf("Owner uid: %d, Name: %s\n", fileStat.st_uid, pwd.pw_name);
    printf("Permissions: %o (octal)\n", fileStat.st_mode & 0777);
    printf("Allocated blocks: %ld\n", fileStat.st_blocks);
    printf("Size of each block: %ld bytes\n", fileStat.st_blksize);
    printf("Inode number: %ld\n", fileStat.st_ino);
    printf("*********************************\n");

    free(buf);
}

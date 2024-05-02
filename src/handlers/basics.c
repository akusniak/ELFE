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
    if (stat(elf_data->file_path, &fileStat) < 0) {
        perror("Failed to get file stats");
        return;
    }

    // Allocate buffer for username retrieval
    size_t bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
    if (bufsize == (size_t)-1) bufsize = 16384;  // Use a large default size if sysconf failed

    char *buf = malloc(bufsize);
    if (!buf) {
        perror("Malloc failed");
        return;
    }

    struct passwd pwd, *result;
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
    printf("Block size: %ld bytes\n", fileStat.st_blksize);
    printf("Inode number: %ld\n", fileStat.st_ino);
    printf("*********************************\n");

    free(buf);
}

#include "../../includes/elfe.h"

/**
 * Function to handle the 'w' option, which prints filesystem statistics of the ELF file.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_w_option(const ElfData *elf_data) {
    struct statfs fs_stats;
    
    printf("**********************************\n");
    if (statfs(elf_data->file_path, &fs_stats) == -1) {
        perror("Failed to get filesystem statistics");
        return;
    }

    // Format the filesystem information
    printf("Filesystem Type: %lx, Block Size: %lu, Total Blocks: %lu, Free Blocks: %lu, Available Blocks: %lu\n",
             fs_stats.f_type, fs_stats.f_bsize, fs_stats.f_blocks, fs_stats.f_bfree, fs_stats.f_bavail);
    printf("**********************************\n");
}

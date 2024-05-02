#include "../../includes/elfe.h"

void handle_w_option(const ElfData *elf_data)
{
    struct statfs fs_stats;
    
    printf("**********************************\n");
    if (statfs(elf_data->file_path, &fs_stats) == -1) {
        perror("Failed to get filesystem statistics");
        return;
    }

    // Format the filesystem information
    printf("Filesystem Type: %lx, Block Size: %lu, Total Blocks: %lu, Free Blocks: %lu, Available Blocks: %lu",
             fs_stats.f_type, fs_stats.f_bsize, fs_stats.f_blocks, fs_stats.f_bfree, fs_stats.f_bavail);
}

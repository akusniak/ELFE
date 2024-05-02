#include "../../includes/elfe.h"

void handle_s_option(ElfData *elf_data)
{
    printf("**********************************\n");
    int section_count;

    if (elf_data->is_64) {
        // If the ELF is 64-bit, get the number of sections from the 64-bit header
        section_count = elf_data->elf64_hdr->e_shnum;
    } else {
        // If the ELF is 32-bit, get the number of sections from the 32-bit header
        section_count = elf_data->elf32_hdr->e_shnum;
    }

    // Format the information about the number of sections into the buffer
    printf("Number of sections in the ELF file: %d", section_count);
}
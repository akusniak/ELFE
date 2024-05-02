#include "../../includes/elfe.h"

void handle_e_option(ElfData *elf_data)
{    
    printf("**********************************\n");
    if (elf_data->is_64) {
        // If the ELF is 64-bit, get the entry point from the 64-bit header
        printf("Entry Point Address: 0x%lx", elf_data->elf64_hdr->e_entry);
    } else {
        // If the ELF is 32-bit, get the entry point from the 32-bit header
        printf("Entry Point Address: 0x%lx", (unsigned long)elf_data->elf32_hdr->e_entry);
    }
}
#include "../../includes/elfe.h"

/**
 * Function to handle the 'e' option, which prints the entry point address of the ELF file.
 * This function determines whether the ELF file is 64-bit or 32-bit, then prints the entry point address accordingly.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_e_option(ElfData *elf_data)
{    
    printf("**********************************\n");
    if (elf_data->is_64) {
        // If the ELF is 64-bit, get the entry point from the 64-bit header
        printf("Entry Point Address: 0x%lx", (unsigned long)elf_data->elf64_hdr->e_entry);
    } else {
        // If the ELF is 32-bit, get the entry point from the 32-bit header
        printf("Entry Point Address: 0x%lx", (unsigned long)elf_data->elf32_hdr->e_entry);
    }
}

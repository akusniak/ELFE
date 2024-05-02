# include "../../includes/elfe.h"

/**
 * Function to handle the 's' option, which prints the number of sections in the ELF file.
 * This function determines the number of sections based on the ELF type (32-bit or 64-bit)
 * and prints this information.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_s_option(ElfData *elf_data)
{
    printf("**********************************\n");
    int section_count;

    // Determine the number of sections based on the ELF type
    if (elf_data->is_64) {
        // If the ELF is 64-bit, get the number of sections from the 64-bit header
        section_count = elf_data->elf64_hdr->e_shnum;
    } else {
        // If the ELF is 32-bit, get the number of sections from the 32-bit header
        section_count = elf_data->elf32_hdr->e_shnum;
    }

    // Print the number of sections
    printf("Number of sections in the ELF file: %d\n", section_count);
}

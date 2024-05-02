#include "../../includes/elfe.h"

/**
 * Function to handle the 'd' option, which displays the content of the .text section in hexadecimal.
 * This function reads and prints the content of the .text section in the ELF file in hexadecimal format.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_d_option(ElfData *elf_data) {
    if (!elf_data) {
        fprintf(stderr, "Error: ELF data is NULL.\n");
        return;
    }

    // Determine the number of sections and the string table index
    int num_sections = elf_data->is_64 ? elf_data->elf64_hdr->e_shnum : elf_data->elf32_hdr->e_shnum;
    int shstrndx = elf_data->is_64 ? elf_data->elf64_hdr->e_shstrndx : elf_data->elf32_hdr->e_shstrndx;

    // Read the section header string table
    off_t shstrtab_offset = elf_data->is_64 ? elf_data->elf64_shdrs[shstrndx].sh_offset : elf_data->elf32_shdrs[shstrndx].sh_offset;
    size_t shstrtab_size = elf_data->is_64 ? elf_data->elf64_shdrs[shstrndx].sh_size : elf_data->elf32_shdrs[shstrndx].sh_size;

    char *sh_str = malloc(shstrtab_size);
    if (!sh_str) {
        perror("Failed to allocate memory for section header string table");
        return;
    }

    if (lseek(elf_data->fd, shstrtab_offset, SEEK_SET) != shstrtab_offset ||
        read(elf_data->fd, sh_str, shstrtab_size) != (ssize_t)shstrtab_size) {
        perror("Failed to read section header string table");
        free(sh_str);
        return;
    }

    for (int i = 0; i < num_sections; i++) {
        uint32_t sh_type = elf_data->is_64 ? ((Elf64_Shdr *)elf_data->elf64_shdrs)[i].sh_type : ((Elf32_Shdr *)elf_data->elf32_shdrs)[i].sh_type;
        if (sh_type == SHT_PROGBITS) {
            const char *name = sh_str + (elf_data->is_64 ? ((Elf64_Shdr *)elf_data->elf64_shdrs)[i].sh_name : ((Elf32_Shdr *)elf_data->elf32_shdrs)[i].sh_name);
            if (!strcmp(name, ".text")) {
                printf("**********************************\n");
                off_t sh_offset = elf_data->is_64 ? ((Elf64_Shdr *)elf_data->elf64_shdrs)[i].sh_offset : ((Elf32_Shdr *)elf_data->elf32_shdrs)[i].sh_offset;
                size_t sh_size = elf_data->is_64 ? ((Elf64_Shdr *)elf_data->elf64_shdrs)[i].sh_size : ((Elf32_Shdr *)elf_data->elf32_shdrs)[i].sh_size;

                // Allocate buffer for the .text section
                char *buffer = malloc(sh_size);
                if (!buffer) {
                    fprintf(stderr, "Failed to allocate memory for the .text section\n");
                    return;
                }

                // Read the .text section content
                if (lseek(elf_data->fd, sh_offset, SEEK_SET) != sh_offset || 
                    read(elf_data->fd, buffer, sh_size) != (ssize_t)sh_size) {
                    perror("Failed to read .text section");
                    free(buffer);
                    free(sh_str);
                    return;
                }

                // Display the .text section in hexadecimal
                for (size_t j = 0; j < sh_size; j++) {
                    printf("%02x ", (unsigned char)buffer[j]);
                    if ((j + 1) % 16 == 0) // New line every 16 bytes
                        printf("\n");
                }
                printf("\n");

                free(buffer);
                free(sh_str);
                break;  // Exit after handling .text section
            }
        }
    }
}

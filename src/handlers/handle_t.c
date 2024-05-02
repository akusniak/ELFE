#include "../../includes/elfe.h"

void print_string_table(int fd, void *shdr_generic, bool is_64);

/**
 * Function to handle the 't' option, which prints section names and their associated string tables.
 * This function iterates over the sections, identifies string table sections, and prints their content.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_t_option(const ElfData *elf_data) {
    printf("**********************************\n");
    char *section_name_strtab = NULL;

    // Load section name string table
    if (elf_data->is_64) {
        Elf64_Shdr shstrtab = elf_data->elf64_shdrs[elf_data->elf64_hdr->e_shstrndx];
        section_name_strtab = malloc(shstrtab.sh_size);
        lseek(elf_data->fd, shstrtab.sh_offset, SEEK_SET);
        read(elf_data->fd, section_name_strtab, shstrtab.sh_size);
    } else {
        Elf32_Shdr shstrtab = elf_data->elf32_shdrs[elf_data->elf32_hdr->e_shstrndx];
        section_name_strtab = malloc(shstrtab.sh_size);
        lseek(elf_data->fd, shstrtab.sh_offset, SEEK_SET);
        read(elf_data->fd, section_name_strtab, shstrtab.sh_size);
    }

    // Iterate over sections
    for (int i = 0; i < (elf_data->is_64 ? elf_data->elf64_hdr->e_shnum : elf_data->elf32_hdr->e_shnum); i++) {
        size_t sh_type = elf_data->is_64 ? elf_data->elf64_shdrs[i].sh_type : elf_data->elf32_shdrs[i].sh_type;
        if (sh_type == SHT_STRTAB) {
            size_t sh_name_offset = elf_data->is_64 ? elf_data->elf64_shdrs[i].sh_name : elf_data->elf32_shdrs[i].sh_name;
            const char *name = section_name_strtab + sh_name_offset;
            printf("%s\n", name);
            print_string_table(elf_data->fd, elf_data->is_64 ? (void *)&elf_data->elf64_shdrs[i] : (void *)&elf_data->elf32_shdrs[i], elf_data->is_64);
        }
    }

    free(section_name_strtab);
}

/**
 * Function to print the content of a string table section.
 *
 * @param fd File descriptor of the ELF file.
 * @param shdr_generic Pointer to the section header structure.
 * @param is_64 Boolean indicating if the ELF is 64-bit.
 */
void print_string_table(int fd, void *shdr_generic, bool is_64) {
    size_t sh_size = is_64 ? ((Elf64_Shdr *)shdr_generic)->sh_size : ((Elf32_Shdr *)shdr_generic)->sh_size;
    off_t sh_offset = is_64 ? ((Elf64_Shdr *)shdr_generic)->sh_offset : ((Elf32_Shdr *)shdr_generic)->sh_offset;

    char *strtab = malloc(sh_size + 1); // Adding an extra byte for null character for safety
    if (!strtab) {
        perror("Failed to allocate memory for string table");
        return;
    }

    if (lseek(fd, sh_offset, SEEK_SET) == -1 || read(fd, strtab, sh_size) != (ssize_t)sh_size) {
        perror("Failed to read string table section");
        free(strtab);
        return;
    }

    strtab[sh_size] = '\0'; // Ensure the last character is null terminated

    char *current_str = strtab;
    while (current_str < strtab + sh_size) {
        if (*current_str) {
            char *next_str = current_str;
            // Find the end of the current string without going beyond the boundaries
            while (next_str < strtab + sh_size && *next_str) {
                next_str++;
            }

            if (next_str < strtab + sh_size) { // Make sure we are still within bounds
                printf("%s\n", current_str);
                current_str = next_str + 1;
            } else {
                break; // If we're at the end, stop the loop
            }
        } else {
            current_str++; // Handle consecutive null characters
        }
    }

    free(strtab);
}

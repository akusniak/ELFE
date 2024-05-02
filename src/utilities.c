#include "../includes/elfe.h"

/**
 * Displays an ASCII art representation of an elf.
 * This function is a fun addition to show a stylized elf using ASCII characters
 * whenever called within the application. It prints the ASCII art to the standard output.
 */
void    have_you_seen_my_elf()
{
    char *elf =
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⣤⣤⣤⣤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⠟⠛⠋⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠳⢶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠏⠀⠀⠀⠀⠀⢾⣦⣄⣀⡀⣀⣠⣤⡶⠟⠀⠀⠀⠀⠀⠀⠈⠻⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣴⡿⠃⠀⣶⠶⠶⠶⠶⣶⣬⣉⠉⠉⠉⢉⣡⣴⡶⠞⠛⠛⠷⢶⡆⠀⠀⠈⢿⠶⠖⠚⠛⠷⠶⢶⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⢀⣠⣴⡾⠛⠋⠉⡉⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⡀⠉⠙⠛⠛⠛⠛⠉⠀⠀⢀⣤⣭⣤⣀⠀⠀⠀⠀⠈⠀⠀⢀⣴⣶⣶⣦⣤⣌⡉⠛⢷⣦⣄⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⢠⣶⠟⠋⣀⣤⣶⠾⠿⣶⡀⠀⠀⠀⣴⡟⢋⣿⣤⡉⠻⣦⠀⠀⠀⠀⠀⠀⢀⣾⠟⢩⣿⣉⠛⣷⣄⠀⠀⠀⠀⢰⡿⠑⠀⠀⠀⠈⠉⠛⠻⣦⣌⠙⢿⣦⠀⠀⠀⠀\n"
    "⠀⣴⡟⠁⣰⡾⠛⠉⠀⠀⠀⢻⣇⡀⠀⢸⣿⠀⣿⠋⠉⣿⠀⢻⡆⠀⠀⠀⠀⠀⣾⡇⢰⡟⠉⢻⣧⠘⣿⠀⠀⠀⠀⣼⠇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⡇⠀⠙⢷⣆⠀⠀\n"
    "⢰⡟⠀⢼⡏⠀⠀⠀⠀⠀⠀⠈⠛⠛⠀⠈⢿⣆⠙⠷⠾⠛⣠⣿⠁⠀⠀⠀⠀⠀⠹⣧⡈⠿⣶⠾⠋⣼⡟⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠶⠶⣶⣤⣌⡻⣧⡀\n"
    "⢸⣧⣯⣬⣥⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠿⢶⡶⠾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠙⠻⢶⣶⣶⠿⠋⠀⠀⠀⠰⣼⡏⠀⠀⠀⠀⠀⠀⢠⣾⠏⠀⠀⠀⠀⠈⠉⠛⠛⠃\n"
    "⠀⠀⠀⠈⠉⠉⠉⠛⠿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⣲⣖⣠⣶⣶⣶⠀⠀⠀⠀⣀⣤⣤⡂⡀⠀⠀⠀⠀⠀⠀⠀⢸⠟⠀⠀⠀⠀⠀⢀⣴⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣄⠀⠀⠀⠀⢠⣾⠋⠁⢿⣇⠀⠀⠀⠀⠀⠀⢙⠉⣹⡇⠻⠷⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣤⣀⡀⠘⠟⠃⠀⠈⢙⣷⡄⠀⠀⠀⣠⣶⠿⠋⠁⠀⠀⠀⠙⣿⠀⠀⢠⣤⣤⣶⠶⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⡄⠀⠀⠀⠀⠀⢸⣿⠀⠀⢰⡿⠁⠀⠀⠀⠀⠀⠀⣠⡿⠀⢠⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣄⠀⠀⠀⠀⠀⢻⣧⣠⡿⠁⠀⠀⠀⠀⠀⠀⠀⠉⠁⣴⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣆⠀⢿⣦⡀⠀⠉⠉⠀⠀⠀⠀⠀⣀⣄⠀⠀⢠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣧⡀⠙⠻⢷⣦⣄⣀⣤⣤⣶⠾⠛⠁⢀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣄⡀⠀⠀⠀⠀⠀⠀⢀⣠⣾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⠷⠶⠶⠾⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\n\n";
    printf("%s", elf);
    return;
}

/**
 * Cleans up and frees all allocated resources held within an ElfData structure.
 * This function ensures no memory leaks occur from the allocations performed during the
 * initialization and use of an ElfData structure. It carefully checks each component of the
 * ElfData structure and frees it if it has been allocated, setting pointers to NULL after freeing
 * to prevent use-after-free errors.
 *
 * @param elf_data Pointer to the ElfData structure to clean up.
 */
void cleanup_elf_data(ElfData *elf_data)
{
    if (!elf_data) {
        return; // Ensure that the pointer is not NULL
    }

    // Close the file descriptor if it is valid
    if (elf_data->fd != -1) {
        close(elf_data->fd);
    }

    // Free the file path string if it is allocated
    if (elf_data->file_path) {
        free(elf_data->file_path);
        elf_data->file_path = NULL;
    }

    // Free the memory for ELF headers and section headers
    if (elf_data->is_64) {
        if (elf_data->elf64_hdr) {
            free(elf_data->elf64_hdr);
            elf_data->elf64_hdr = NULL;
        }
        if (elf_data->elf64_shdrs) {
            free(elf_data->elf64_shdrs);
            elf_data->elf64_shdrs = NULL;
        }
    } else {
        if (elf_data->elf32_hdr) {
            free(elf_data->elf32_hdr);
            elf_data->elf32_hdr = NULL;
        }
        if (elf_data->elf32_shdrs) {
            free(elf_data->elf32_shdrs);
            elf_data->elf32_shdrs = NULL;
        }
    }

    // Finally, free the structure itself
    free(elf_data);
}

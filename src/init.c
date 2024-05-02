#include "../includes/elfe.h"

/**
 * Initializes an ElfData structure from a specified file containing ELF (Executable and Linkable Format) data.
 * This function opens the file, reads and verifies the ELF header, and depending on whether the file is a 32-bit or 64-bit ELF,
 * allocates and reads the appropriate header and section headers.
 *
 * @param filename The path to the ELF file to be processed.
 * @param elf_data Pointer to an uninitialized ElfData structure where the parsed ELF data will be stored.
 * @return int Returns 0 on success, or -1 if an error occurs, setting an appropriate error message with perror.
 */
int init_elf_data(const char *filename, ElfData *elf_data) {
    // Initialize the ElfData structure to zero to ensure all fields are clean.
    memset(elf_data, 0, sizeof(ElfData));
    
    // Set the initial file descriptor to an invalid value as a safeguard.
    elf_data->fd = -1;

    // Open the specified file in read-only mode.
    elf_data->fd = open(filename, O_RDONLY);
    if (elf_data->fd == -1) {
        perror("Failed to open file");
        return -1;  // Exit on file open failure.
    }

    // Buffer to hold the ELF identification bytes.
    unsigned char e_ident[EI_NIDENT];
    // Read the ELF identification from the file.
    if (read(elf_data->fd, e_ident, EI_NIDENT) != EI_NIDENT) {
        perror("Failed to read ELF identification");
        close(elf_data->fd);  // Ensure to close the file descriptor on failure.
        return -1;
    }

    // Verify the magic numbers to confirm this is indeed an ELF file.
    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3) {
        perror("not an elf, gimme an elf please");
        close(elf_data->fd);  // Close the file descriptor on failure.
        return -1;
    }

    // Check the class of the ELF file and set the is_64 flag accordingly.
    elf_data->is_64 = (e_ident[EI_CLASS] == ELFCLASS64);
    // Rewind the file descriptor to the start of the file after reading the identification.
    lseek(elf_data->fd, 0, SEEK_SET);

    if (elf_data->is_64) {
        // Allocate memory for the 64-bit ELF header.
        elf_data->elf64_hdr = malloc(sizeof(Elf64_Ehdr));
        if (!elf_data->elf64_hdr) {
            perror("Failed to allocate memory for ELF 64 header");
            close(elf_data->fd);  // Cleanup on allocation failure.
            return -1;
        }
        // Read the 64-bit ELF header from the file.
        if (read(elf_data->fd, elf_data->elf64_hdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
            perror("Failed to read ELF 64 header");
            close(elf_data->fd);
            free(elf_data->elf64_hdr);
            elf_data->elf64_hdr = NULL;  // Prevent dangling pointer.
            return -1;
        }
        // Allocate memory and read the section headers for a 64-bit ELF file.
        elf_data->elf64_shdrs = malloc(sizeof(Elf64_Shdr) * elf_data->elf64_hdr->e_shnum);
        if (!elf_data->elf64_shdrs || (ssize_t)lseek(elf_data->fd, elf_data->elf64_hdr->e_shoff, SEEK_SET) != (ssize_t)elf_data->elf64_hdr->e_shoff ||
            read(elf_data->fd, elf_data->elf64_shdrs, sizeof(Elf64_Shdr) * elf_data->elf64_hdr->e_shnum) != (ssize_t)sizeof(Elf64_Shdr) * elf_data->elf64_hdr->e_shnum) {
            perror("Failed to read section headers for ELF 64");
            free(elf_data->elf64_hdr);
            free(elf_data->elf64_shdrs);
            close(elf_data->fd);
            return -1;
        }
    } else {
        // Allocate memory for the 32-bit ELF header.
        elf_data->elf32_hdr = malloc(sizeof(Elf32_Ehdr));
        if (!elf_data->elf32_hdr) {
            perror("Failed to allocate memory for ELF 32 header");
            close(elf_data->fd);  // Cleanup on allocation failure.
            return -1;
        }
        // Read the 32-bit ELF header from the file.
        if (read(elf_data->fd, elf_data->elf32_hdr, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr)) {
            perror("Failed to read ELF 32 header");
            close(elf_data->fd);
            free(elf_data->elf32_hdr);
            elf_data->elf32_hdr = NULL;  // Prevent dangling pointer.
            return -1;
        }
        // Allocate memory and read the section headers for a 32-bit ELF file.
        elf_data->elf32_shdrs = malloc(sizeof(Elf32_Shdr) * elf_data->elf32_hdr->e_shnum);
        if (!elf_data->elf32_shdrs || lseek(elf_data->fd, elf_data->elf32_hdr->e_shoff, SEEK_SET) != elf_data->elf32_hdr->e_shoff ||
            read(elf_data->fd, elf_data->elf32_shdrs, sizeof(Elf32_Shdr) * elf_data->elf32_hdr->e_shnum) != (ssize_t)sizeof(Elf32_Shdr) * elf_data->elf32_hdr->e_shnum) {
            perror("Failed to read section headers for ELF 32");
            free(elf_data->elf32_hdr);
            free(elf_data->elf32_shdrs);
            close(elf_data->fd);
            return -1;
        }
    }

    // Duplicate the filename to store it in the ElfData structure.
    elf_data->file_path = strdup(filename);
    if (!elf_data->file_path) {
        perror("Failed to allocate memory for file path");
        close(elf_data->fd);  // Cleanup on failure.
        // Free all previously allocated memory.
        if (elf_data->is_64) {
            free(elf_data->elf64_hdr);
            free(elf_data->elf64_shdrs);
            elf_data->elf64_hdr = NULL;
            elf_data->elf64_shdrs = NULL;
        } else {
            free(elf_data->elf32_hdr);
            free(elf_data->elf32_shdrs);
            elf_data->elf32_hdr = NULL;
            elf_data->elf32_shdrs = NULL;
        }
        return -1;
    }

    return 0;  // Return success if all operations complete successfully.
}

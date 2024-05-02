#include "../includes/elfe.h"

int init_elf_data(const char *filename, ElfData *elf_data) {
    // Zero initialize the structure
    memset(elf_data, 0, sizeof(ElfData));
    
    // Initialize the file descriptor as invalid
    elf_data->fd = -1;

    // Try to open the file
    elf_data->fd = open(filename, O_RDONLY);
    if (elf_data->fd == -1) {
        perror("Failed to open file");
        return -1;
    }

    unsigned char e_ident[EI_NIDENT];
    if (read(elf_data->fd, e_ident, EI_NIDENT) != EI_NIDENT) {
        perror("Failed to read ELF identification");
        close(elf_data->fd);
        return -1;
    }

    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3) {
        perror("not an elf, gimme an elf please");
        close(elf_data->fd);
        return -1;
    }

    elf_data->is_64 = (e_ident[EI_CLASS] == ELFCLASS64);
    lseek(elf_data->fd, 0, SEEK_SET); // Rewind after reading e_ident

    if (elf_data->is_64) {
        elf_data->elf64_hdr = malloc(sizeof(Elf64_Ehdr));
        if (!elf_data->elf64_hdr) {
            perror("Failed to allocate memory for ELF 64 header");
            close(elf_data->fd);
            return -1;
        }
        if (read(elf_data->fd, elf_data->elf64_hdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
            perror("Failed to read ELF 64 header");
            close(elf_data->fd);
            free(elf_data->elf64_hdr);
            elf_data->elf64_hdr = NULL;
            return -1;
        }
        // Allocate and load section headers for 64-bit ELF
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
        elf_data->elf32_hdr = malloc(sizeof(Elf32_Ehdr));
        if (!elf_data->elf32_hdr) {
            perror("Failed to allocate memory for ELF 32 header");
            close(elf_data->fd);
            return -1;
        }
        if (read(elf_data->fd, elf_data->elf32_hdr, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr)) {
            perror("Failed to read ELF 32 header");
            close(elf_data->fd);
            free(elf_data->elf32_hdr);
            elf_data->elf32_hdr = NULL;
            return -1;
        }
        // Allocate and load section headers for 32-bit ELF
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

    elf_data->file_path = strdup(filename);
    if (!elf_data->file_path) {
        perror("Failed to allocate memory for file path");
        close(elf_data->fd);
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

    return 0;
}

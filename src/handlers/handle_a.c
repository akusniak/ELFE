#include "../../includes/elfe.h"

void handle_a_option(ElfData *elf_data)
{
    // Initialisation de variables pour le positionnement et la lecture
    off_t shoff = elf_data->is_64 ? elf_data->elf64_hdr->e_shoff : elf_data->elf32_hdr->e_shoff;
    uint16_t shnum = elf_data->is_64 ? elf_data->elf64_hdr->e_shnum : elf_data->elf32_hdr->e_shnum;
    uint16_t shentsize = elf_data->is_64 ? elf_data->elf64_hdr->e_shentsize : elf_data->elf32_hdr->e_shentsize;

    void* shdrs = elf_data->is_64 ? malloc(shnum * sizeof(Elf64_Shdr)) : malloc(shnum * sizeof(Elf32_Shdr));
    if (!shdrs) {
        perror("Failed to allocate memory for section headers");
        return;
    }

    if (lseek(elf_data->fd, shoff, SEEK_SET) != shoff) {
        perror("Failed to seek to section header table");
        free(elf_data->elf64_shdrs);
        return;
    }

    if (lseek(elf_data->fd, shoff, SEEK_SET) != shoff) {
        perror("Failed to seek to section header table");
        free(shdrs);  // Libération des en-têtes de section en cas d'échec de lseek
        return;
    }

    // Lecture des en-têtes de section
    if (read(elf_data->fd, shdrs, shnum * shentsize) != shnum * shentsize) {
        perror("Failed to read section headers");
        free(shdrs);  // Libération en cas d'échec de la lecture
        return;
    }

    // Lire la table des chaînes de la section des en-têtes
    uint16_t strtab_index = elf_data->is_64 ? elf_data->elf64_hdr->e_shstrndx : elf_data->elf32_hdr->e_shstrndx;
    off_t strtab_offset = elf_data->is_64 ? elf_data->elf64_shdrs[strtab_index].sh_offset : elf_data->elf32_shdrs[strtab_index].sh_offset;
    uint64_t strtab_size = elf_data->is_64 ? elf_data->elf64_shdrs[strtab_index].sh_size : elf_data->elf32_shdrs[strtab_index].sh_size;

    char *strtab = malloc(strtab_size);
    if (!strtab) {
        perror("Failed to allocate memory for string table");
        free(shdrs);
        return;
    }

    if (lseek(elf_data->fd, strtab_offset, SEEK_SET) != strtab_offset || read(elf_data->fd, strtab, strtab_size) != (ssize_t)strtab_size) {
        perror("Failed to read string table");
        free(strtab);
        free(shdrs);
        return;
    }

    // Afficher les noms et les tailles des sections
    for (uint32_t i = 0; i < shnum; i++) {
        const char *name = &strtab[elf_data->is_64 ? elf_data->elf64_shdrs[i].sh_name : elf_data->elf32_shdrs[i].sh_name];
        uint64_t size = elf_data->is_64 ? elf_data->elf64_shdrs[i].sh_size : elf_data->elf32_shdrs[i].sh_size;
        printf("Section %u: %s, size: %lu bytes\n", i, name, size);
    }
    if (shdrs)
        free(shdrs);
    if (strtab)
        free(strtab);
}
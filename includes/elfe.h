#ifndef RELF_H
# define RELF_H

// include the necessary headers
# include <unistd.h> // for getopt
# include <stdio.h> // for printf
# include <stdlib.h> // for return values

#include <getopt.h> // for getopt long options
#include <sys/vfs.h>    // Header for statfs

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>

#include <stdbool.h>
#include <pwd.h>
#include <sys/types.h>

// define the return values
# define ELF_DETECTED 1
# define NOT_AN_ELF 0

# define FAILED_OPEN 0
# define FAILED_READ 0

# define SYS_32 ELFCLASS32
# define SYS_64 ELFCLASS64

# define FAILED_INIT -1
# define SUCCESS_INIT 0

typedef struct InfoNode {
    char *info;
    struct InfoNode *next;
}   InfoNode;


typedef struct ElfData {
    int             fd;                 // File descriptor for the ELF file
    bool            is_64; // structure pour les headers
    char            *file_path;
    union {
        Elf32_Ehdr  *elf32_hdr;        // Pointeur vers l'en-tête ELF 32 bits
        Elf64_Ehdr  *elf64_hdr;        // Pointeur vers l'en-tête ELF 64 bits
    };
    union {
        Elf32_Shdr  *elf32_shdrs;      // Pointeur vers les en-têtes de section ELF 32 bits
        Elf64_Shdr  *elf64_shdrs;      // Pointeur vers les en-têtes de section ELF 64 bits
    };
}   ElfData;



/* Utilities */

void    have_you_seen_my_elf();
void cleanup_elf_data(ElfData *elf_data);


/* Init */

int init_elf_data(const char *filename, ElfData *elf_data);


/* Handlers */

void    help(void);
void handle_basic(ElfData *elf_data);
void handle_a_option(ElfData *elf_data);
void handle_d_option(ElfData *elf_data);
void handle_e_option(ElfData *elf_data);
void handle_l_option(const ElfData *elf_data);
void handle_s_option(ElfData *elf_data);
void handle_t_option(const ElfData *elf_data);
void handle_w_option(const ElfData *elf_data);

#endif
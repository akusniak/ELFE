#ifndef ELFE_H
#define ELFE_H

// Include necessary standard library headers
#include <unistd.h>      // For POSIX APIs like getopt
#include <stdio.h>       // For I/O operations
#include <stdlib.h>      // For general utilities like malloc
#include <getopt.h>      // For getopt_long function to parse command-line options
#include <sys/vfs.h>     // For filesystem statistics
#include <sys/types.h>   // For data types
#include <fcntl.h>       // For file control options
#include <sys/stat.h>    // For stat functions
#include <sys/mman.h>    // For memory management declarations
#include <elf.h>         // For ELF format definitions
#include <string.h>      // For string operations
#include <stdbool.h>     // For boolean type
#include <pwd.h>         // For password structure
#include <sys/statvfs.h> // For filesystem statistics

// Define return values for ELF detection
#define ELF_DETECTED 1
#define NOT_AN_ELF 0

// Define error codes for file operations
#define FAILED_OPEN 0
#define FAILED_READ 0

// Define constants for system architecture types
#define SYS_32 ELFCLASS32
#define SYS_64 ELFCLASS64

// Define initialization statuses
#define FAILED_INIT -1
#define SUCCESS_INIT 0

// Structure to hold linked list of information nodes
typedef struct InfoNode {
    char *info;
    struct InfoNode *next;
} InfoNode;

// Structure to manage ELF data within the program
typedef struct ElfData {
    int fd;              // File descriptor for the ELF file
    bool is_64;          // True if ELF is 64-bit, false if 32-bit
    char *file_path;     // Path to the ELF file
    union {
        Elf32_Ehdr *elf32_hdr;  // Pointer to the ELF 32-bit header
        Elf64_Ehdr *elf64_hdr;  // Pointer to the ELF 64-bit header
    };
    union {
        Elf32_Shdr *elf32_shdrs;  // Pointer to the ELF 32-bit section headers
        Elf64_Shdr *elf64_shdrs;  // Pointer to the ELF 64-bit section headers
    };
} ElfData;

/* Utility functions */
void have_you_seen_my_elf();
void cleanup_elf_data(ElfData *elf_data);

/* Initialization function */
int init_elf_data(const char *filename, ElfData *elf_data);

/* Command handlers */
void help(void);
void handle_basic(ElfData *elf_data);
void handle_a_option(ElfData *elf_data);
void handle_d_option(ElfData *elf_data);
void handle_e_option(ElfData *elf_data);
void handle_l_option(const ElfData *elf_data);
void handle_s_option(ElfData *elf_data);
void handle_t_option(const ElfData *elf_data);
void handle_w_option(const ElfData *elf_data);

#endif // ELFE_H

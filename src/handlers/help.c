#include "../../includes/elfe.h"

void    help(void)
{
    printf("Usage: ./elfe <file> [-dsaetl] [--c-wizard]\n");
    printf("Options:\n");
    printf("  -d: Display the dynamic section\n");
    printf("  -s: Display the symbol table\n");
    printf("  -a: Display the section headers\n");
    printf("  -e: Display the ELF header\n");
    printf("  -t: Display the program headers\n");
    printf("  -l: Display the library dependencies\n");
    printf("  --c-wizard: Display the wizard\n");
    return;
}
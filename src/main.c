#include "../includes/elfe.h"

static struct option long_options[] = {
    {"c-wizard", no_argument, NULL, 'w'}, // w for wizard
    {0, 0, 0, 0}
};

int main(int argc, char **argv)
{
    int         opt = 0;
    int         option_index = 0;
    ElfData     *elf_data;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file> [-dsaetl] [--c-wizard]\n", argv[0]);
        return EXIT_FAILURE;
    }

    elf_data = malloc(sizeof(ElfData));
    if (elf_data == NULL) {
        perror("Failed to allocate memory for elf_data");
        return EXIT_FAILURE;
    }


    if (init_elf_data(argv[1], elf_data) == FAILED_INIT) {
        cleanup_elf_data(elf_data);
        return EXIT_FAILURE;
    }

    // have_you_seen_my_elf();
    handle_basic(elf_data);

    while ((opt = getopt_long(argc, argv, "hdsaetl", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'h':
                help();
                break;
            case 'd':
                handle_d_option(elf_data);
                break;
            case 's':
                handle_s_option(elf_data);
                break;
            case 'a':
                handle_a_option(elf_data);
                break;
            case 'e':
                handle_e_option(elf_data);
                break;
            case 't':
                handle_t_option(elf_data);
                break;
            case 'l':
                handle_l_option(elf_data);
                break;
            case 'w':
                handle_w_option(elf_data);
                break;
            default:
                break;
        }
    }
    cleanup_elf_data(elf_data);
    return EXIT_SUCCESS;
}
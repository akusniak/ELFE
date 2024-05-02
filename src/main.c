#include "../includes/elfe.h"

// Definition of long options for command line arguments
static struct option long_options[] = {
    {"c-wizard", no_argument, NULL, 'w'}, // Option for the wizard mode
    {0, 0, 0, 0}                          // End of options marker
};

/**
 * Main function of the ELF data processing tool.
 * This function handles command line arguments and orchestrates the loading, processing,
 * and cleanup of ELF data based on the options provided by the user.
 *
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * @return int Returns EXIT_SUCCESS on successful execution and EXIT_FAILURE on errors.
 */
int main(int argc, char **argv)
{
    int         opt = 0;            // Variable to capture the option selected by getopt_long
    int         option_index = 0;   // Index of the current option being processed
    ElfData     *elf_data;          // Pointer to ElfData structure for storing ELF file information

    // Check for minimum required arguments (program name and at least one other)
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file> [-dsaetl] [--c-wizard]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate memory for ElfData structure
    elf_data = malloc(sizeof(ElfData));
    if (elf_data == NULL) {
        perror("Failed to allocate memory for elf_data");
        return EXIT_FAILURE;
    }

    // Initialize the ElfData structure from the first argument
    if (init_elf_data(argv[1], elf_data) == FAILED_INIT) {
        cleanup_elf_data(elf_data);  // Cleanup resources if initialization fails
        return EXIT_FAILURE;
    }

    have_you_seen_my_elf(); // Function to check if the ELF has been seen before ;)

    // Function handle_basic to perform basic handling based on the ElfData; commented out: have_you_seen_my_elf();
    handle_basic(elf_data);

    // Process command line options using getopt_long
    while ((opt = getopt_long(argc, argv, "hdsaetl", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'h': // Handle help option
                help();
                break;
            case 'd': // Handle 'd' option
                handle_d_option(elf_data);
                break;
            case 's': // Handle 's' option
                handle_s_option(elf_data);
                break;
            case 'a': // Handle 'a' option
                handle_a_option(elf_data);
                break;
            case 'e': // Handle 'e' option
                handle_e_option(elf_data);
                break;
            case 't': // Handle 't' option
                handle_t_option(elf_data);
                break;
            case 'l': // Handle 'l' option
                handle_l_option(elf_data);
                break;
            case 'w': // Handle wizard mode option
                handle_w_option(elf_data);
                break;
            default:  // Handle unspecified option
                break;
        }
    }
    // Cleanup all allocated resources and exit
    cleanup_elf_data(elf_data);
    return EXIT_SUCCESS;
}

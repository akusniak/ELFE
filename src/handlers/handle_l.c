# include "../../includes/elfe.h"

/**
 * Function to handle the 'l' option, which prints the linked libraries of the ELF file.
 * This function searches for the dynamic section containing the list of linked libraries,
 * then prints each linked library.
 *
 * @param elf_data Pointer to the ElfData structure containing ELF file information.
 */
void handle_l_option(const ElfData *elf_data)
{
    if (elf_data->is_64) {
        // If the ELF is 64-bit
        Elf64_Shdr *shdrs = elf_data->elf64_shdrs;
        char *dynstr = NULL;
        
        // Find the dynamic section and its associated string table
        for (int i = 0; i < elf_data->elf64_hdr->e_shnum; ++i) {
            if (shdrs[i].sh_type == SHT_STRTAB) {
                lseek(elf_data->fd, shdrs[i].sh_offset, SEEK_SET);
                dynstr = malloc(shdrs[i].sh_size);
                read(elf_data->fd, dynstr, shdrs[i].sh_size);
                break;
            }
        }

        if (!dynstr) {
            return;  // Dynamic string table not found
        }

        // Process the dynamic section to find linked libraries
        for (int i = 0; i < elf_data->elf64_hdr->e_shnum; ++i) {
            if (shdrs[i].sh_type == SHT_DYNAMIC) {
                int num_dyn = shdrs[i].sh_size / sizeof(Elf64_Dyn);
                Elf64_Dyn *dyn = malloc(num_dyn * sizeof(Elf64_Dyn));
                lseek(elf_data->fd, shdrs[i].sh_offset, SEEK_SET);
                read(elf_data->fd, dyn, num_dyn * sizeof(Elf64_Dyn));

                for (int j = 0; j < num_dyn; j++) {
                    if (dyn[j].d_tag == DT_NEEDED) {
                        printf("Linked library: %s\n", dynstr + dyn[j].d_un.d_val);
                    }
                }
                free(dyn);
                break; // Process only the first SHT_DYNAMIC section
            }
        }

        free(dynstr);
    } else {
        // For 32-bit ELF
        Elf32_Shdr *shdrs = elf_data->elf32_shdrs;
        char *dynstr = NULL;
        
        // Find the dynamic section and its associated string table
        for (int i = 0; i < elf_data->elf32_hdr->e_shnum; ++i) {
            if (shdrs[i].sh_type == SHT_STRTAB) {
                lseek(elf_data->fd, shdrs[i].sh_offset, SEEK_SET);
                dynstr = malloc(shdrs[i].sh_size);
                read(elf_data->fd, dynstr, shdrs[i].sh_size);
                break;
            }
        }

        if (!dynstr) {
            return;  // Dynamic string table not found
        }

        // Process the dynamic section to find linked libraries
        for (int i = 0; i < elf_data->elf32_hdr->e_shnum; ++i) {
            if (shdrs[i].sh_type == SHT_DYNAMIC) {
                int num_dyn = shdrs[i].sh_size / sizeof(Elf32_Dyn);
                Elf32_Dyn *dyn = malloc(num_dyn * sizeof(Elf32_Dyn));
                lseek(elf_data->fd, shdrs[i].sh_offset, SEEK_SET);
                read(elf_data->fd, dyn, num_dyn * sizeof(Elf32_Dyn));

                for (int j = 0; j < num_dyn; j++) {
                    if (dyn[j].d_tag == DT_NEEDED) {
                        printf("Linked library: %s\n", dynstr + dyn[j].d_un.d_val);
                    }
                }
                free(dyn);
                break; // Process only the first SHT_DYNAMIC section
            }
        }
        free(dynstr);
    }
}

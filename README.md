# ELFE - Executable and Linkable Format Explorer
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⣤⣤⣤⣤⣤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⠟⠛⠋⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠳⢶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠏⠀⠀⠀⠀⠀⢾⣦⣄⣀⡀⣀⣠⣤⡶⠟⠀⠀⠀⠀⠀⠀⠈⠻⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣴⡿⠃⠀⣶⠶⠶⠶⠶⣶⣬⣉⠉⠉⠉⢉⣡⣴⡶⠞⠛⠛⠷⢶⡆⠀⠀⠈⢿⠶⠖⠚⠛⠷⠶⢶⣶⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⢀⣠⣴⡾⠛⠋⠉⡉⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⡀⠉⠙⠛⠛⠛⠛⠉⠀⠀⢀⣤⣭⣤⣀⠀⠀⠀⠀⠈⠀⠀⢀⣴⣶⣶⣦⣤⣌⡉⠛⢷⣦⣄⠀⠀⠀⠀⠀⠀
    ⠀⠀⢠⣶⠟⠋⣀⣤⣶⠾⠿⣶⡀⠀⠀⠀⣴⡟⢋⣿⣤⡉⠻⣦⠀⠀⠀⠀⠀⠀⢀⣾⠟⢩⣿⣉⠛⣷⣄⠀⠀⠀⠀⢰⡿⠑⠀⠀⠀⠈⠉⠛⠻⣦⣌⠙⢿⣦⠀⠀⠀⠀
    ⠀⣴⡟⠁⣰⡾⠛⠉⠀⠀⠀⢻⣇⡀⠀⢸⣿⠀⣿⠋⠉⣿⠀⢻⡆⠀⠀⠀⠀⠀⣾⡇⢰⡟⠉⢻⣧⠘⣿⠀⠀⠀⠀⣼⠇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⡇⠀⠙⢷⣆⠀⠀
    ⢰⡟⠀⢼⡏⠀⠀⠀⠀⠀⠀⠈⠛⠛⠀⠈⢿⣆⠙⠷⠾⠛⣠⣿⠁⠀⠀⠀⠀⠀⠹⣧⡈⠿⣶⠾⠋⣼⡟⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠶⠶⣶⣤⣌⡻⣧⡀
    ⢸⣧⣯⣬⣥⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠿⢶⡶⠾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠙⠻⢶⣶⣶⠿⠋⠀⠀⠀⠰⣼⡏⠀⠀⠀⠀⠀⠀⢠⣾⠏⠀⠀⠀⠀⠈⠉⠛⠛⠃
    ⠀⠀⠀⠈⠉⠉⠉⠛⠿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⣲⣖⣠⣶⣶⣶⠀⠀⠀⠀⣀⣤⣤⡂⡀⠀⠀⠀⠀⠀⠀⠀⢸⠟⠀⠀⠀⠀⠀⢀⣴⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣄⠀⠀⠀⠀⢠⣾⠋⠁⢿⣇⠀⠀⠀⠀⠀⠀⢙⠉⣹⡇⠻⠷⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣤⣀⡀⠘⠟⠃⠀⠈⢙⣷⡄⠀⠀⠀⣠⣶⠿⠋⠁⠀⠀⠀⠙⣿⠀⠀⢠⣤⣤⣶⠶⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⡄⠀⠀⠀⠀⠀⢸⣿⠀⠀⢰⡿⠁⠀⠀⠀⠀⠀⠀⣠⡿⠀⢠⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣄⠀⠀⠀⠀⠀⢻⣧⣠⡿⠁⠀⠀⠀⠀⠀⠀⠀⠉⠁⣴⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣆⠀⢿⣦⡀⠀⠉⠉⠀⠀⠀⠀⠀⣀⣄⠀⠀⢠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣧⡀⠙⠻⢷⣦⣄⣀⣤⣤⣶⠾⠛⠁⢀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣄⡀⠀⠀⠀⠀⠀⠀⢀⣠⣾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⠷⠶⠶⠾⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
    
    @sqrt28 - Sam Barbosa
    @akusniak - Axel Kusniak

**ELFE** is a program designed to display detailed information about ELF (Executable and Linkable Format) binary files. It provides a comprehensive analysis tool to extract and print various metadata and sections of ELF files, ensuring a deeper understanding of the file's contents.

## 🌟 Features
- **Basic Information Display:** By default, without any arguments, the program displays basic information such as file size, owner UID and name, file permissions in octal format, number of allocated blocks, size of these blocks, and the inode number.
- **Extended Options:**
  - `-d`: Prints the `.text` section of the binary in hexadecimal format.
  - `-s`: Prints the number of sections in the binary.
  - `-a`: Prints a list of sections, including their names and sizes.
  - `-e`: Prints the entrypoint address of the program.
  - `-t`: Prints the data available in the string table section (if exists).
  - `-l`: Prints the names of all linked libraries.
  - `--c-wizard` : Prints the capabilities of the filesystem on the block device where the binary is saved.

## 📦 Prerequisites
- GCC compiler or an equivalent C compiler that supports C99 or later.

## 🔨 Installation
To compile ELFE, use the provided Makefile with the following commands:

### Compilation
```bash
make all
```
This command compiles the source files and links the generated object files into an executable named `elfe`.

### Clean Up
To remove object files and the executable, use:
```bash
make fclean
```
This will clean up all compiled files, ensuring a clean state for a fresh compilation.

### Rebuilding
```bash
make re
```
This command cleans up all compiled files and recompiles the project from scratch.

## 🚀 Usage
To run ELFE, specify the path to an ELF file as the argument. Here are some examples of how to execute the program with various options:

```bash
./elfe <path_to_elf_file> [options]
```

For example:
```bash
./elfe ./example.elf -d -s
```
This command displays the `.text` section in hexadecimal and the number of sections in the specified ELF file.

## ❗ Error Handling
- If no file or an incorrect file is specified, the program will prompt: "not an elf, gimme an elf please" and will exit.
- Usage information is displayed if the program is launched without any arguments or with incorrect options.

## 🤝 Contributing
Contributions to ELFE are welcome! Please feel free to fork the repository, make changes, and submit pull requests. You can also open issues if you find bugs or have feature suggestions.

## 📄 License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute the software as per the license.
# List of source files
SRCS = src/main.c \
       src/utilities.c \
       src/handlers/handle_a.c \
       src/handlers/handle_d.c \
       src/handlers/handle_e.c \
       src/handlers/handle_l.c \
       src/handlers/handle_s.c \
       src/handlers/handle_t.c \
       src/handlers/handle_w.c \
       src/handlers/basics.c \
       src/handlers/help.c \
       src/init.c

# Convert source file paths in SRCS from .c to .o and change directory to 'objects/'
OBJS = $(SRCS:src/%.c=objects/%.o)

# General arguments variable for flexible usage
ARGS = 

# Compiler to use
CC = gcc

# Command to remove files
RM = rm -f

# Compiler flags for warning levels and errors
CFLAGS = -Wall -Wextra -Werror

# Debugging flags
DFLAGS = -g -O0

# Name of the final executable
NAME = elfe

# Terminal color codes for output messages
COLOUR_GREEN=\033[0;32m
COLOUR_ORANGE=\033[0;33m
COLOUR_RESET=\033[0m

# Rule to compile .c files into .o files, outputting progress with color
objects/%.o: src/%.c
	@echo "$(COLOUR_ORANGE)Compiling... $@$(COLOUR_RESET)"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the final executable, outputting progress with color
$(NAME): $(OBJS)
	@echo "$(COLOUR_GREEN)Linking executable: $@$(COLOUR_RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Default rule to make the final executable
all: $(NAME)

# Rule to build the project with debugging information
debug: CFLAGS += $(DFLAGS)
debug: $(NAME)

# Rule to run the executable with Valgrind for memory leak checking
valgrind: debug
	@echo "$(COLOUR_GREEN)Running Valgrind on $(NAME)...$(COLOUR_RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

# Rule to clean up object files, outputting progress with color
clean:
	@echo "$(COLOUR_ORANGE)Cleaning up object files...$(COLOUR_RESET)"
	@$(RM) -r objects

# Rule to fully clean the project (both object files and the executable)
fclean: clean
	@echo "$(COLOUR_ORANGE)Cleaning up executable...$(COLOUR_RESET)"
	@$(RM) $(NAME)

# Rule to rebuild the project from scratch
re: fclean all

# Special targets that do not correspond to actual files
.PHONY: all clean fclean re debug valgrind

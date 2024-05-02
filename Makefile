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

OBJS = $(SRCS:src/%.c=objects/%.o)

ARGS = 
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g -O0
NAME = elfe

COLOUR_GREEN=\033[0;32m
COLOUR_ORANGE=\033[0;33m
COLOUR_RESET=\033[0m

objects/%.o: src/%.c
	@echo "$(COLOUR_ORANGE)Compiling... $@$(COLOUR_RESET)"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(COLOUR_GREEN)Linking executable: $@$(COLOUR_RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

debug: CFLAGS += $(DFLAGS)
debug: $(NAME)

valgrind: debug
	@echo "$(COLOUR_GREEN)Running Valgrind on $(NAME)...$(COLOUR_RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

clean:
	@echo "$(COLOUR_ORANGE)Cleaning up object files...$(COLOUR_RESET)"
	@$(RM) -r objects

fclean: clean
	@echo "$(COLOUR_ORANGE)Cleaning up executable...$(COLOUR_RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug valgrind

NAME = minishell

CC = cc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

LIBFT = ./libft/libft.a

SRC = main.c \
	handling_signals.c \
	init.c \
	valid_input.c \
	utils.c quotes.c \
	create_data.c \
	execute.c \
	builtins/echo.c \
	builtins/cd.c \
	builtins/pwd.c \
	builtins/env.c \
	builtins/exit.c \
	builtins/export.c \
	builtins/export2.c \
	builtins/unset.c \
 	utils_split.c \
 	child_or_parent.c \
	free.c \
	redirect_out.c \
	redirect_in.c \
	path.c \
	expander.c \
	execute_utils.c \
	expander_utils.c \
	create_data_utils.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	echo "created"
	$(CC) $(CFLAGS) $(OBJ) -lreadline $(LIBFT) -o $(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJ)
		echo "OBJ deleted"

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)
		echo "minishell deleted"

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re

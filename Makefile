NAME = minishell

CC = cc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

LIBFT = ./libft/libft.a

SRC = main.c handling_signals.c valid_input.c utils.c quotes.c create_data.c \
	execute.c builtins/echo.c utils_split.c

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

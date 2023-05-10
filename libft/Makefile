CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
       ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c\
       ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
       ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c\
       get_next_line.c get_next_line_bonus.c get_next_line_utils.c\
       ft_printf.c ft_prt_char.c ft_prt_hexadecimal.c ft_prt_number.c ft_prt_string.c ft_ptr_pointer.c\
       ft_ptr_unsigned.c
       
      

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)
		

%o:%c
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

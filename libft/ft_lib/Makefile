CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putendl.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  \
	  ft_strlen.c \
	  ft_strlen_esp.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strdup.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim_white_space.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_atoi.c \
	  ft_itoa.c \
	  ft_swap.c \
	  ft_reverse.c \
	  \
	  ft_sort_wordtab.c \
	  ft_intlen.c \
	  ft_strsort.c \
	  ft_strcheck_char.c \
	  ft_sort_params.c \
	  ft_sort_params_rev.c \
	  ft_charcheck_in_str.c \
	  ft_strtrim_letter.c \
	  \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstadd_back.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  \
	  get_next_line.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRC) $(CFLAGS) -I ../includes/
	@echo "\033[33;40m===> Lib: Creation des .o et"
	@ar rc $(NAME) $(OBJ)
	@echo "===> Lib: Creation de la libft\033[33;37m"
	@ranlib libft.a

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

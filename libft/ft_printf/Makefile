CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c \
	  ft_onlyesp.c \
	  ft_putstr.c \
	  ft_putstr_c.c \
	  ft_initflags.c \
	  ft_strlen.c \
	  ft_putarg.c \
	  ft_strnew.c \
	  ft_nbesp.c \
	  ft_atoi.c \
	  ft_itoa.c \
	  ft_long_itoa.c \
	  ft_unsigned_itoa.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memalloc.c \
	  ft_strdup.c \
	  ft_charcheck_in_str.c \
	  ft_isdigit.c \
	  ft_intlen.c \
	  ft_strlen_per.c \
	  ft_strjoin.c \
	  ft_strnjoin.c \
	  ft_strjoin_per.c \
	  ft_strjoin_per_aux.c \
	  ft_strjoin_per_aux2.c \
	  ft_strncat.c \
	  ft_strncpy.c \
	  ft_strequ.c \
	  ft_pow.c \
	  \
	  ft_printf.c \
	  ft_putflags.c \
	  ft_transfo_int.c \
	  ft_transfo_hexoct.c \
	  ft_binary.c \
	  ft_bin_to_hexoct.c \
	  ft_putprecision.c \
	  ft_putprecision_ho.c \
	  ft_putwidth.c \
	  ft_split_bytes.c \
	  ft_long_str.c \
	  ft_check_flags.c
OBJ = $(SRC:.c=.o)
LIB = -L -lftprintf
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC) -I ../includes/
	@ar rc $(NAME) $(OBJ)
	@echo "ft_printf: Creation de la libftprintf"
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

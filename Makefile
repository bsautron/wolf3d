# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 09:35:27 by bsautron          #+#    #+#              #
#    Updated: 2015/01/28 09:35:37 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = main.c \
	  key_hook.c \
	  key_press_hook.c \
	  key_release_hook.c \
	  pointer_motion_hook.c \
	  expose_hook.c \
	  \
	  ft_getmap.c \
	  ft_zoom_map.c \
	  ft_calcul.c \
	  ft_make_increment.c \
	  ft_draw.c \
	  ft_minicase.c \
	  ft_dtor.c
OBJ = $(SRC:.c=.o)
NAME = wolf3d
FLAGS = -Wall -Wextra -Werror
LX11 = -L/usr/X11/lib -lmlx -lXext -lX11
LIB = -L./libft/ft_lib -lft
LPRINTF= -L./libft/ft_printf -lftprintf

all: $(NAME)

$(NAME):
	@make -C libft/ft_lib/
	@make -C libft/ft_printf/
	@$(CC) $(FLAGS) -I libft/includes/ -I/usr/X11/include -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(LPRINTF) $(LX11)
	@echo "===> Wolf3d: Made"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~

re: fclean all

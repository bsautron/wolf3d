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
OBJ = $(SRC:%.c=obj/%.o)
HEADER = $(DIR_H)/ft_minishell.h \
		 $(DIR_H)/libft.h \
		 $(DIR_H)/libl.h \
		 $(DIR_H)/libld.h \
		 $(DIR_H)/get_next_line.h
NAME = wolf3d
FLAGS = -Wall -Wextra -Werror
LX11 = -framework OpenGL -framework AppKit
LIB = -L./libft/ft_lib -lft
LPRINTF= -L./libft/ft_printf -lftprintf

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(LPRINTF) $(LX11)
	@echo "===> Wolf3d: Made"

libs:
	@make -C libft/

obj/%.o: %.c includes/wolf3d.h
	@$(CC) -o $@ $(FLAGS) -I includes/ -c $<

dor:
	@mkdir obj 2>/dev/null || env -i

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 09:35:27 by bsautron          #+#    #+#              #
#    Updated: 2015/03/31 07:47:58 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = main.c \
	  key_press_hook.c \
	  key_release_hook.c \
	  p_motion_hook.c \
	  expose_hook.c \
	  \
	  ft_getmap.c \
	  ft_zoom_map.c \
	  ft_calcul.c \
	  ft_viseur.c \
	  ft_arme.c \
	  ft_mur.c \
	  ft_go.c \
	  ft_make_increment.c \
	  ft_draw.c \
	  ft_minicase.c \
	  ft_dtor.c
OBJ = $(SRC:%.c=.obj/%.o)
HEADER = $(DIR_H)/ft_minishell.h \
		 $(DIR_H)/libft.h \
		 $(DIR_H)/libl.h \
		 $(DIR_H)/libld.h \
		 $(DIR_H)/myx.h \
		 $(DIR_H)/get_next_line.h
NAME = wolf3d
FLAGS = -Wall -Wextra -Werror
LX11 = -framework OpenGL -framework AppKit -L./minilibx_macos/ -lmlx
LIB = -L./libft/ -lft

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(LX11)
	@echo "===> Wolf3d: Made"

libs:
	@make -C libft/

.obj/%.o: %.c includes/wolf3d.h
	@echo "	$<"
	@$(CC) -o $@ $(FLAGS) -I includes/ -c $<

dor:
	@mkdir .obj 2>/dev/null || env -i

clean:
	@rm -f $(OBJ)
	@rmdir .obj 2>/dev/null || env -i

fclean: clean
	@rm -f $(NAME)

re: fclean all

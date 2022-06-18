# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 03:03:20 by abziouzi          #+#    #+#              #
#    Updated: 2022/06/18 06:18:42 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g

LIBFT		=	libft

SRC			=	src/so_long.c			\
				src/check_map.c			\
				src/check_map_utils.c	\
				src/global_utils.c		\
				src/movement.c			\
				src/render.c			\
				src/render_utils.c

OBJ			=	$(SRC:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C $(LIBFT)
				@echo " [ .. ] | Compiling libft.."
				$(CC) $(CFLAGS) $^ -o $@ -lmlx -framework AppKit -framework OpenGl -L$(LIBFT) -lft
				@echo " [ OK ] | Libft ready!"

%.o			:	%.c inc/so_long.h
				$(CC) $(CFLAGS) -c $< -o $@ -I gnl -I libft

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all 	clean	fclean	re

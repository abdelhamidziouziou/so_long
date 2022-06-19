# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 03:03:20 by abziouzi          #+#    #+#              #
#    Updated: 2022/06/19 08:09:12 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror -g

LIBFT			=	inc/libft

SRC				=	mandatory/so_long.c				\
					mandatory/check_map.c			\
					mandatory/check_map_utils.c		\
					mandatory/global_utils.c		\
					mandatory/movement.c			\
					mandatory/render.c				\
					mandatory/render_utils.c

SRC_BONUS		=	bonus/so_long_bonus.c			\
					bonus/check_map_bonus.c			\
					bonus/check_map_utils_bonus.c	\
					bonus/global_utils_bonus.c		\
					bonus/movement_bonus.c			\
					bonus/render_bonus.c			\
					bonus/render_utils_bonus.c

OBJ				=	$(SRC:%.c=%.o)

OBJ_BONUS		=	$(SRC_BONUS:%.c=%.o)

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					make -C $(LIBFT)
					@echo " [ .. ] | Compiling libft.."
					$(CC) $(CFLAGS) $^ -o $@ -lmlx -framework AppKit -framework OpenGl -L$(LIBFT) -lft
					@echo " [ OK ] | Libft ready!"

bonus			:	$(NAME_BONUS)

$(NAME_BONUS)	:	$(OBJ_BONUS)
					make -C $(LIBFT)
					@echo " [ .. ] | Compiling libft.."
					$(CC) $(CFLAGS) $^ -o $@ -lmlx -framework AppKit -framework OpenGl -L$(LIBFT) -lft
					@echo " [ OK ] | Libft ready!"

%.o				:	%.c inc/so_long.h
					$(CC) $(CFLAGS) -c $< -o $@ -I gnl -I libft

clean			:
					rm -f $(OBJ) $(OBJ_BONUS)

fclean			:	clean
					rm -f $(NAME) $(NAME_BONUS)

re				:	fclean all

.PHONY			:	all	bonus	clean	fclean	re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 03:03:20 by abziouzi          #+#    #+#              #
#    Updated: 2022/06/21 00:29:57 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror -g

MLX_FLAGS		=	-lmlx -framework AppKit -framework OpenGl

LIBFT			=	inc/libft

SRC				=	src_mandatory/so_long.c				\
					src_mandatory/check_map.c			\
					src_mandatory/check_map_utils.c		\
					src_mandatory/global_utils.c		\
					src_mandatory/movement.c			\
					src_mandatory/render.c				\
					src_mandatory/render_utils.c

SRC_BONUS		=	src_bonus/so_long_bonus.c			\
					src_bonus/check_map_bonus.c			\
					src_bonus/check_map_utils_bonus.c	\
					src_bonus/global_utils_bonus.c		\
					src_bonus/movement_bonus.c			\
					src_bonus/render_bonus.c			\
					src_bonus/render_utils_bonus.c		\
					src_bonus/rendering_bonus.c

OBJ				=	$(SRC:%.c=%.o)

OBJ_BONUS		=	$(SRC_BONUS:%.c=%.o)

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					make -C $(LIBFT)
					@echo " [ .. ] | Compiling libft.."
					$(CC) $(CFLAGS) $^ -o $@ $(MLX_FLAGS) -L$(LIBFT) -lft
					@echo " [ OK ] | Libft ready!"

bonus			:	$(NAME_BONUS)

$(NAME_BONUS)	:	$(OBJ_BONUS)
					make -C $(LIBFT)
					@echo " [ .. ] | Compiling libft.."
					$(CC) $(CFLAGS) $^ -o $@ $(MLX_FLAGS) -L$(LIBFT) -lft
					@echo " [ OK ] | Libft ready!"

%.o				:	%.c inc/so_long.h
					$(CC) $(CFLAGS) -c $< -o $@ -I inc/libft

clean			:
					rm -f $(OBJ) $(OBJ_BONUS)
					make -C $(LIBFT) clean

fclean			:	clean
					rm -f $(NAME) $(NAME_BONUS)
					make -C $(LIBFT) fclean

re				:	fclean all

.PHONY			:	all	bonus	clean	fclean	re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 03:03:20 by abziouzi          #+#    #+#              #
#    Updated: 2022/06/18 22:36:31 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror -g

LIBFT			=	libft

SRC				=	src/so_long.c						\
					src/check_map.c						\
					src/check_map_utils.c				\
					src/global_utils.c					\
					src/movement.c						\
					src/render.c						\
					src/render_utils.c

SRC_BONUS		=	bonus/src/so_long_bonus.c			\
					bonus/src/check_map_bonus.c			\
					bonus/src/check_map_utils_bonus.c	\
					bonus/src/global_utils_bonus.c		\
					bonus/src/movement_bonus.c			\
					bonus/src/render_bonus.c			\
					bonus/src/render_utils_bonus.c

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

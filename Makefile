# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 02:51:05 by abziouzi          #+#    #+#              #
#    Updated: 2022/04/14 02:54:49 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

OS				= ${shell uname}

CC				= gcc

CFLAGS			= -Wall -Wextra

SRC				= so_long.c so_long_utils.c so_long.h

OBJ				= ${SRC:.c=.o}

RM				= rm -f

LIBMLXMAC		= make -C mlx/

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac
endif

$(NAME): 		$(OBJ)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif

all:			${NAME}

bonus:			re

clean:
				${RM} ${OBJ}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re

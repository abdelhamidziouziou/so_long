# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 02:51:05 by abziouzi          #+#    #+#              #
#    Updated: 2022/04/24 21:58:24 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRC:.c=.o}

RM			= rm -rf

SRC 		= ./src/so_long.c\
			  ./src/so_long_utils.c\
			  ./ft_printf/libftprintf.a

INC			= ./inc/so_long.h \
				./ft_printf/libftprintf.a

all: so_long

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(SRC) -o so_long

clean:
		   	$(RM) $(OBJS)

fclean:
		   	$(RM) $(OBJS)
	   		$(RM) $(NAME)

re:			fclean all

.PHONY : all clean fclean re bonus

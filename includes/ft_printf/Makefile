# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:27:00 by abziouzi          #+#    #+#              #
#    Updated: 2021/12/16 20:02:46 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I ft_printf.h

AR = ar crs

RM = rm  -rf

FILES = ft_printf.c		ft_putchar.c	ft_putnbr.c		ft_put_uns_nbr.c	ft_putstr.c		ft_put_hexa.c	ft_nbr_len.c		ft_put_ptr.c

OBJ = ${FILES:%.c=%.o}

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	gcc $(FLAGS) -c $(FILES) -I ft_printf.h

.PHONY: all bonus clean fclean re

all: $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:49:21 by abziouzi          #+#    #+#              #
#    Updated: 2022/05/26 14:18:09 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS_NAME = so_long_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDE = include

SRC = src

COMMON_FILES = render/key_handler.c \
		render/destroy_notify.c \
		utils/global_utils.c \
		utils/obj_utils.c \
		utils/destroy_cleanly.c \
		utils/error_utils.c \
		utils/free_utils.c \
		utils/list_utils.c \
		parser/map_utils.c \
		parser/get_next_line.c \
		parser/get_next_line_utils.c

SRC_FILES = $(COMMON_FILES) \
		render/render_utils.c \
		render/move_utils.c \
		so_long.c

BNS_FILES = $(COMMON_FILES) \
		render/move_utils_bonus.c \
		render/render_utils_bonus.c \
		so_long_bonus.c

MOBJ = $(SRC_FILES:%.c=src/%.o)
BOBJ = $(BNS_FILES:%.c=src/%.o)

all : $(NAME)

$(NAME) : $(MOBJ)
	@echo "Linking all object files"
	@$(CC) $^ -o $@ -lmlx -framework OpenGL -framework AppKit
	@echo "Executable file generated successfully!"

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BOBJ)
	@echo "Linking all object files"
	@$(CC) $^ -o $@ -lmlx -framework OpenGL -framework AppKit
	@echo "Executable file generated successfully!"

$(SRC)/%.o : $(SRC)/%.c $(INCLUDE)/so_long.h
	@echo "Compiling $@"
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INCLUDE)

clean :
	@echo "Cleaning..."
	@rm -f $(MOBJ) $(BOBJ)

fclean : clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

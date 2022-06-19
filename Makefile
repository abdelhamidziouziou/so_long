# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 03:03:20 by abziouzi          #+#    #+#              #
#    Updated: 2022/06/20 00:04:56 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

# **************************************************************************** #
#	Norminette
# **************************************************************************** #

NORMINETTE	:=	$(shell which norminette)

ifeq (, $(shell which norminette))
	NORMINETTE := ${HOME}/.norminette/norminette.rb
endif

# **************************************************************************** #
#	Compilation
# **************************************************************************** #

CC				=	cc

FLAGS			=	-Wall -Wextra -Werror -g

DIR_HEADERS		=	./inc/so_long.h

MLX_FLAGS		=	-lmlx -framework AppKit -framework OpenGl

LIBFT			=	./inc/libft

RM				=	rm -rf

# --------------------------------------------------------------------- #
#	Mandatory Files
# --------------------------------------------------------------------- #

NAME			=	so_long

DIR_SRC			=	./src_mandatory/

SRCS			=	so_long.c			\
					check_map.c			\
					check_map_utils.c	\
					global_utils.c		\
					movement.c			\
					render.c			\
					render_utils.c

SRC				=	$(SRCS)

DIR_OBJ			=	./obj_mandatory/

OBJ				=	$(SRC:%.c=$(DIR_OBJ)%.o)

# --------------------------------------------------------------------- #
#	Bonus Files
# --------------------------------------------------------------------- #

NAME_BONUS		=	so_long_bonus

DIR_SRC_BONUS	=	./src_bonus/

SRCS_BONUS		=	so_long_bonus.c				\
					check_map_bonus.c			\
					check_map_utils_bonus.c		\
					global_utils_bonus.c		\
					movement_bonus.c			\
					render_bonus.c				\
					render_utils_bonus.c

SRC_BONUS		=	$(SRCS_BONUS)

DIR_OBJ_BONUS	=	./obj_bonus/

OBJ_BONUS		=	$(SRC_BONUS:%.c=$(DIR_OBJ_BONUS)%.o)
# --------------------------------------------------------------------- #
#	Rules
# --------------------------------------------------------------------- #

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					make -C $(LIBFT)
					@printf "\033[2K\r$(_GREEN) All files compiled into 'inc/libft'. $(_END)✅\n"
					@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(MLX_FLAGS) -o $(NAME) -L$(LIBFT) -lft
					@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)✅\n"

$(OBJ)			:	| $(DIR_OBJ)


$(DIR_OBJ)%.o	:	$(DIR_SRC)/$(SRC)%.c
					@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛ "
					@$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJ)		:
					@mkdir $(DIR_OBJ)

# Bonus Part

bonus			:	$(NAME_BONUS)



$(LIBFT)		:	| $(DIR_OBJ)
					make -C $(LIBFT)

clean			:
					$(RM) $(DIR_OBJ) $(DIR_OBJ_BONUS) inc/libft/*.o

fclean			:	clean
					$(RM) $(NAME) $(NAME_BONUS)

re				:	fclean all

# Norme

norm:
				@$(NORMINETTE) $(DIR_SRC)
				@$(NORMINETTE) $(DIR_HEADERS)

.PHONY:			all bonus	clean fclean re norm

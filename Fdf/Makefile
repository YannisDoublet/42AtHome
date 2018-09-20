# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 17:35:39 by yadouble          #+#    #+#              #
#    Updated: 2018/09/20 20:30:06 by yadouble         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast -flto -march=native
FRAMEWORK = -framework OpenGL -framework AppKit
SRCS_DIR = srcs
OBJ_DIR = obj
SRCS = fdf.c \
		main.c \
		check.c \
		utils.c \
		bresenham.c \
		draw.c \
		tools.c \
		memory_manager.c \
		window.c
SRCS := $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ = $(subst $(SRCS_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(FRAMEWORK) \
	libft/libft.a minilibx_macos/libmlx.a

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -o $@ -Iincludes -c $(CFLAGS) $<

clean :
	@make -C libft clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)

re : fclean all

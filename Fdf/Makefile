# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 17:35:39 by yadouble          #+#    #+#              #
#    Updated: 2018/08/15 21:07:31 by yadouble         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJ_DIR = obj
SRCS = fdf.c \
		main.c \
		parse.c \
		utils.c
SRCS := $(addprefix $(SRCS_DIR)/,$(SRCS))
OBJ = $(subst $(SRCS_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) libft/libft.a

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

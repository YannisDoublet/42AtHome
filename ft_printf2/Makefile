# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 20:44:54 by yadouble          #+#    #+#              #
#    Updated: 2018/06/05 16:18:30 by yadouble         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libftprintf.a
NAMETEST = ft_printf
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJ_DIR = obj
HEADER = include
SRC = 	ft_printf.c \
		parsing.c \
		parsing_step.c \
		process.c \
		process_int.c \
		tools.c \
		buffer.c \
		format_option.c \
		decimal_option.c \
		process_hexadecimal.c \
		process_unsigned.c \
		process_octal.c
SRCS = $(addprefix $(SRCS_DIR)/,$(SRC))
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(HEADER) -o $@ -c $<

test : $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	$(CC) -o $(NAMETEST) $(OBJS) libft/libft.a ./main.c

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(SRCS_DIR)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAMETEST)
	@make fclean -C libft

re: fclean all
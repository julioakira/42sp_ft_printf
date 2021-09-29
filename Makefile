# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:30:59 by jakira-p          #+#    #+#              #
#    Updated: 2021/09/29 19:06:53 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= clang

RM	= rm -rf

AR	= ar -rcs

CFLAGS	= -Wall -Werror -Wextra

MAIN_DIR = ft_printf/

TYPE_HANDLERS_DIR = ft_printf/type_handlers/

UTILS_DIR = ft_printf/utils/

all : $(NAME)

## Requires a main.c file in $(MAIN_DIR)
debug: $(NAME) ft_printf/main.c
	$(CC) ft_printf/main.c $(NAME) -o printf

$(NAME): ft_printf/ft_printf.a libft/libft.a
	$(AR) $(NAME) ft_printf/build/*.o libft/*.o

ft_printf/ft_printf.a: $(TYPE_HANDLERS_DIR)*.c $(UTILS_DIR)*.c $(MAIN_DIR)ft_printf.c
	make all -C ft_printf

libft/libft.a: libft/*.c
	make all -C libft

.PHONY: clean fclean re

clean:
	make clean -C ft_printf
	make clean -C libft

fclean: clean
	make fclean -C ft_printf
	rm $(NAME)
	make fclean -C libft

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:30:59 by jakira-p          #+#    #+#              #
#    Updated: 2021/09/29 14:44:16 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= clang

RM	= rm -rf

AR	= ar -rcs

CFLAGS	= -Wall -Werror -Wextra

all : $(NAME)

$(NAME): ft_printf/ft_printf.a libft/libft.a
	$(AR) $(NAME) ft_printf/build/*.o libft/*.o

ft_printf/ft_printf.a: ft_printf/type_handlers/*.c ft_printf/utils/*.c ft_printf/ft_printf.c
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
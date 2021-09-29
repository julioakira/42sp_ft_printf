# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 14:21:05 by jakira-p          #+#    #+#              #
#    Updated: 2021/09/29 14:26:54 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

RM	= rm -rf

AR	= ar -rcs

CFLAGS	= -Wall -Werror -Wextra

INCLUDES	= -I../libft

NAME	= ft_printf.a

BUILD_DIR	= build/

TYPE_HANDLERS_DIR = type_handlers/

UTILS_DIR = utils/

SRC	=	ft_printf.c \
		$(UTILS_DIR)eval_conversions.c \
		$(UTILS_DIR)long_to_hex.c \
		$(UTILS_DIR)struct_utils.c \
		$(UTILS_DIR)utils.c \
		$(TYPE_HANDLERS_DIR)handle_char.c \
		$(TYPE_HANDLERS_DIR)handle_decimal.c \
		$(TYPE_HANDLERS_DIR)handle_hex.c \
		$(TYPE_HANDLERS_DIR)handle_pointer.c \
		$(TYPE_HANDLERS_DIR)handle_print.c \
		$(TYPE_HANDLERS_DIR)handle_result.c \
		$(TYPE_HANDLERS_DIR)handle_string.c \
		$(TYPE_HANDLERS_DIR)handle_uint.c

OBJS	=	$(addprefix $(BUILD_DIR),$(notdir $(SRC:.c=.o)))

.PHONY : clean fclean re

all : $(NAME)

$(BUILD_DIR)ft_printf.o: ft_printf.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$(notdir $@) $(INCLUDES)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

$(BUILD_DIR)%.o: $(UTILS_DIR)%.c
		@mkdir -p $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$(notdir $@) $(INCLUDES)

$(BUILD_DIR)%.o: $(TYPE_HANDLERS_DIR)%.c
		@mkdir -p $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$(notdir $@) $(INCLUDES)

clean:
		$(RM) $(OBJS) $(BUILD_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 14:21:05 by jakira-p          #+#    #+#              #
#    Updated: 2021/09/29 10:33:33 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

RM	= rm -rf

AR	= ar -rcs

CFLAGS	= -Wall -Werror -Wextra

INCLUDES	= -I../libft

NAME	= ft_printf.a

BUILD_DIR	= build/

SRC	=	ft_printf.c \
		utils/eval_conversions.c \
		utils/long_to_hex.c \
		utils/struct_utils.c \
		utils/utils.c \
		type_handlers/handle_char.c \
		type_handlers/handle_decimal.c \
		type_handlers/handle_hex.c \
		type_handlers/handle_pointer.c \
		type_handlers/handle_print.c \
		type_handlers/handle_result.c \
		type_handlers/handle_string.c \
		type_handlers/handle_uint.c

OBJS	=	$(addprefix $(BUILD_DIR),${SRC:.c=.o})

.PHONY : clean fclean re

${NAME}: ${OBJS}
		${AR} ${NAME} ${$(notdir ${OBJS})}

${OBJS}: ${SRC}
		@mkdir -p ${BUILD_DIR}
		${CC} ${CFLAGS} -c $< -o ${BUILD_DIR}$(notdir $@) ${INCLUDES}

all : ${NAME}

clean:
		${RM} ${OBJS} ${BUILD_DIR}

fclean: clean
		${RM} ${NAME}

re: fclean all
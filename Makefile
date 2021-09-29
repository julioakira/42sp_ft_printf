# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 20:06:38 by jakira-p          #+#    #+#              #
#    Updated: 2021/09/29 10:56:59 by jakira-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

RM	= rm -rf

AR	= ar -rcs

INCLUDES	= -I../libft -I../ft_printf

CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

LIBFT_DIR	= libft

FT_PRINTF_DIR	= ft_printf

BUILD_DIR		= build

FT_PRINTF_SRC = ft_printf.c \
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

LIBFT_SRC = ft_atoi.c \
				ft_calloc.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strnstr.c \
				ft_tolower.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_memchr.c \
				ft_memset.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_toupper.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_litoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

LIBFT_SRC	:= $(addprefix ${LIBFT_DIR}/${BUILD_DIR}/,${LIBFT_SRC})
LIBFT_OBJ	:= ${LIBFT_SRC:.c=.o}

FT_PRINTF_OBJ	:= $(addprefix ${BUILD_DIR}/,${FT_PRINTF_SRC:.c=.o})
FT_PRINTF_SRC	:= $(addprefix ${FT_PRINTF_DIR}/,${FT_PRINTF_SRC})

all : ${NAME}

clean:
	${RM} ${FT_PRINTF_OBJ} ${BUILD_DIR} ${LIBFT_OBJ} ${LIBFT_DIR}/${BUILD_DIR} ${LIBFT_D}/libft.a

bonus: all

fclean: clean
	${RM} ${NAME}

re:	fclean all

${LIBFT_DIR}/libft.a : ${LIBFT_OBJ}
	${AR} ${LIBFT_DIR}/libft.a ${LIBFT_OBJ}

${LIBFT_DIR}/${BUILD_DIR}/%.o : ${LIBFT_DIR}/%.c
	@mkdir -p ${LIBFT_DIR}/${BUILD_DIR}
	${CC} ${CFLAGS} $< -c -o $@

${BUILD_DIR}/%.o : ${FT_PRINTF_DIR}/%.c
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} $< -c -o ${BUILD_DIR}/$(notdir $@) ${INCLUDES}

${NAME} : ${LIBFT_DIR}/libft.a ${FT_PRINTF_OBJ}
	@cp ${LIBFT_DIR}/libft.a ${NAME}
	${AR} ${NAME} ${$(notdir ${FT_PRINTF_OBJ})}

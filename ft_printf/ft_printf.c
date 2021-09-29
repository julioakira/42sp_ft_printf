/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 04:28:36 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_metadata	*data;

	data = new_metadata(ft_strdup(str));
	va_start(args, str);
	handle_print(data, args);
	va_end(args);
	return (data->char_counter);
}

// gcc -Werror -Wextra -Wall ft_printf.c type_handlers/handle_result.c eval_conversions.c utils.c long_to_hex.c struct_utils.c type_handlers/handle_print.c type_handlers/handle_char.c type_handlers/handle_decimal.c type_handlers/handle_hex.c type_handlers/handle_pointer.c type_handlers/handle_string.c type_handlers/handle_uint.c ../libft/libft.a && ./a.out
int main(void)
{
	char *ptr_test = "Hello, world!";
	ft_printf("Hello %c %d %i %u %s %x %X %p", 'a', 100, 999, -10, "i am a string!", 86447, 86447, &ptr_test);
}

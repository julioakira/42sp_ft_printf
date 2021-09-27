/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/27 06:23:06 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	idx;
	char	result;

	idx = 0;
	va_start(args, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			idx++;
			result = eval_conversions(str[idx]);
			if (result)
			{
				idx--;
				handle_result(result, args);
				idx++;
			}
		}
		else
			ft_putchar_fd(str[idx], 1);
		idx++;
	}
	va_end(args);
	return (0);
}

// gcc -Werror -Wextra -Wall ft_printf.c handle_result.c eval_conversions.c utils.c long_to_hex.c libft/libft.a && ./a.out
int main(void)
{
	char *ptr_test = "Hello, world!";
	ft_printf("Hello! %c %d %i %s %x %X %p", 'a', 100, 999, "i am a string!", 86447, 86447, &ptr_test);
}
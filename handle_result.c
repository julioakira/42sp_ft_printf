/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:05:58 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/27 05:11:24 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_result(char spec, va_list args)
{
	int		signed_int;
	char	*int_result;

	if (spec == 'c')
	{
		signed_int = va_arg(args, int);
		ft_putchar_fd(signed_int, 1);
	}
	if (spec == 'd' || spec == 'i' || spec == 'u')
	{
		signed_int = va_arg(args, int);
		int_result = ft_itoa(signed_int);
		ft_putstr_fd(int_result, 1);
		free_and_nullify(int_result);
	}
	if (spec == 's')
		handle_string(args);
	if (spec == 'x')
		handle_hex(args, 0);
	if (spec == 'X')
		handle_hex(args, 1);
	if (spec == 'p')
		handle_pointer(args);
}

void	handle_hex(va_list args, int is_upper)
{
	unsigned long	nbr;
	char			*result;

	nbr = va_arg(args, unsigned long);
	if (is_upper)
		result = to_hex(nbr, 1);
	else
		result = to_hex(nbr, 0);
	ft_putstr_fd(result, 1);
	free_and_nullify(result);
}

void	handle_string(va_list args)
{
	char	*str_result;

	str_result = va_arg(args, char *);
	ft_putstr_fd(str_result, 1);
	str_result = NULL;
}

void	handle_pointer(va_list args)
{
	void			*ptr;
	unsigned long	ptr_value;

	ptr_value = va_arg(args, unsigned long);
	ptr = to_hex(ptr_value, 0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(ptr, 1);
	free_and_nullify(ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:05:58 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 18:59:45 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_result(t_metadata *data, va_list args)
{
	if (data->conversion == 'c')
		handle_char(args, data);
	if (data->conversion == 'd'
		|| data->conversion == 'i')
		handle_decimal(args, data);
	if (data->conversion == 'u')
		handle_uint(args, data);
	if (data->conversion == 's')
		handle_string(args, data);
	if (data->conversion == 'x')
		handle_hex(args, data, 0);
	if (data->conversion == 'X')
		handle_hex(args, data, 1);
	if (data->conversion == 'p')
		handle_pointer(args, data);
	if (data->conversion == '%')
		handle_percentage(data);
}

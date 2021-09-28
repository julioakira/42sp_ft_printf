/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:05:58 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 02:31:17 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_result(t_metadata *data, va_list args)
{
	if (data->conversion == 'c')
		handle_char(args);
	if (data->conversion == 'd'
		|| data->conversion == 'i')
		handle_decimal(args);
	if (data->conversion == 'u')
		handle_uint(args);
	if (data->conversion == 's')
		handle_string(args);
	if (data->conversion == 'x')
		handle_hex(args, 0);
	if (data->conversion == 'X')
		handle_hex(args, 1);
	if (data->conversion == 'p')
		handle_pointer(args);
}

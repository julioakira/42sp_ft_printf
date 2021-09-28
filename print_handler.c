/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:21:17 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 00:24:46 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_handler(t_metadata *data, va_list args)
{
	while (data->content[data->curr_idx])
	{
		if (data->content[data->curr_idx] == '%')
		{
			data->curr_idx++;
			data->conversion = eval_conversions(data, data->curr_idx);
			if (data->conversion)
			{
				data->curr_idx--;
				handle_result(data, args);
				data->curr_idx++;
			}
		}
		else
			ft_putchar_fd(data->content[data->curr_idx], 1);
		data->curr_idx++;
	}
}

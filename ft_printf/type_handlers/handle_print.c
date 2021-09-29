/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:21:17 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 04:28:05 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_print(t_metadata *data, va_list args)
{
	while (data->content[data->curr_idx])
	{
		if (data->content[data->curr_idx] == '%')
		{
			data->curr_idx++;
			data->conversion = eval_conversions(data);
			if (data->conversion)
			{
				data->curr_idx--;
				handle_result(data, args);
				data->curr_idx++;
			}
		}
		else
		{
			ft_putchar_fd(data->content[data->curr_idx], 1);
			data->char_counter++;
		}
		data->curr_idx++;
	}
}

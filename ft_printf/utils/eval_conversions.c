/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:10:48 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 15:58:53 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
c = single char
s = string
p = void *pointer printed in hexadecimal
d = int: -2147483648 to 2147483647
i = decimal number
u = unsigned int: 0 to 4294967295
x = hexadecimal lowercase
X = hexadecimal upercase
% = %
*/

int	eval_conversions(t_metadata *data)
{
	size_t	idx;

	if (!data->flags)
		data->flags = ft_strdup("cspdiuxX%");
	idx = 0;
	while (data->flags[idx])
	{
		if ((data->content[data->curr_idx]) == data->flags[idx])
		{
			data->conversion = data->content[data->curr_idx];
			return (data->conversion);
		}
		idx++;
	}
	return (0);
}

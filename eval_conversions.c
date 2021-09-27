/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:10:48 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/27 06:19:21 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	eval_conversions(const char spec)
{
	char	*allowed;
	size_t	idx;

	allowed = ft_strdup("cspdiuxX%");
	idx = 0;
	while (allowed[idx])
	{
		if (spec == allowed[idx])
		{
			free(allowed);
			allowed = NULL;
			return (spec);
		}
		idx++;
	}
	free_and_nullify(allowed);
	return (0);
}

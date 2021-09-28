/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:52:27 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 00:54:10 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

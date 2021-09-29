/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:52:27 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 04:27:54 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_hex(va_list args, t_metadata *data, int is_upper)
{
	unsigned long	nbr;
	char			*result;

	nbr = va_arg(args, unsigned long);
	if (is_upper)
		result = to_hex(nbr, 1);
	else
		result = to_hex(nbr, 0);
	data->char_counter += ft_strlen(result);
	ft_putstr_fd(result, 1);
	free_and_nullify(result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:36:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 19:05:09 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_decimal(va_list args, t_metadata *data)
{
	int		signed_int;
	char	*int_result;

	signed_int = va_arg(args, int);
	int_result = ft_itoa(signed_int);
	data->char_counter += ft_strlen(int_result);
	ft_putstr_fd(int_result, 1);
	free_and_nullify(int_result);
}
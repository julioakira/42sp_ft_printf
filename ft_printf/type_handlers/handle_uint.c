/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:24:30 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 04:28:13 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_uint(va_list args, t_metadata *data)
{
	unsigned int	uint;
	char			*uint_result;

	uint = va_arg(args, unsigned int);
	uint_result = ft_litoa(uint);
	ft_putstr_fd(uint_result, 1);
	data->char_counter += ft_strlen(uint_result);
	free_and_nullify(uint_result);
}
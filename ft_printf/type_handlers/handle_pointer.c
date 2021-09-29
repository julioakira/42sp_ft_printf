/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:53:58 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 04:28:01 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_pointer(va_list args, t_metadata *data)
{
	char			*ptr;
	unsigned long	ptr_value;

	ptr_value = va_arg(args, unsigned long);
	ptr = to_hex(ptr_value, 0);
	ft_putstr_fd("0x", 1);
	data->char_counter += 2;
	ft_putstr_fd(ptr, 1);
	data->char_counter += ft_strlen(ptr);
	free_and_nullify(ptr);
}

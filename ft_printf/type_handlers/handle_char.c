/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:54:43 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 19:12:12 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_char(va_list args, t_metadata *data)
{
	unsigned int	uint;

	uint = (char)va_arg(args, unsigned int);
	ft_putchar_fd(uint, 1);
	data->char_counter++;
}

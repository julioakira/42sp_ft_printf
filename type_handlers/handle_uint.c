/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:24:30 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 03:10:06 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Needs corrections on uint overflow
void	handle_uint(va_list args)
{
	unsigned int	uint;
	char			*uint_result;

	uint = va_arg(args, unsigned int);
	uint_result = ft_litoa(uint);
	ft_putstr_fd(uint_result, 1);
	free_and_nullify(uint_result);
}
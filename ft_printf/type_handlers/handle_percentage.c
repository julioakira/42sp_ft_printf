/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:50:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 18:59:04 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_percentage(t_metadata *data)
{
	unsigned int	uint;

	uint = 37;
	ft_putchar_fd(uint, 1);
	data->char_counter++;
}

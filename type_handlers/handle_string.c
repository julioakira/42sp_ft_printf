/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:53:26 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 00:53:36 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_string(va_list args)
{
	char	*str_result;

	str_result = va_arg(args, char *);
	ft_putstr_fd(str_result, 1);
	str_result = NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:19:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/10/12 20:06:09 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_metadata	*data;
	int			char_counter;
	char		*str_cpy;

	str_cpy = ft_strdup(str);
	data = new_metadata(str_cpy);
	va_start(args, str);
	handle_print(data, args);
	va_end(args);
	char_counter = data->char_counter;
	free_struct(&data);
	return (char_counter);
}

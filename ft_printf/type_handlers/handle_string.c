/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:53:26 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 16:28:18 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_string(va_list args, t_metadata *data)
{
	char	*str_result;
	char	*temp;

	temp = NULL;
	str_result = va_arg(args, char *);
	if (!str_result)
	{
		temp = ft_strdup("(null)");
		ft_putstr_fd(temp, 1);
		data->char_counter += ft_strlen(temp);
		free_and_nullify(temp);
	}
	else
	{
		ft_putstr_fd(str_result, 1);
		data->char_counter += ft_strlen(str_result);
		str_result = NULL;
	}
}

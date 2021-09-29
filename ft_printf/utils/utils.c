/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 04:05:08 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 18:22:08 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	free_and_nullify(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

char	*ft_str_tolower(char *str)
{
	char	*lower;
	int		i;
	int		size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(str) + 1;
	lower = ft_calloc(sizeof(char), size);
	if (!lower)
		return (NULL);
	while (str[i] && i < size)
	{
		lower[i] = ft_tolower(str[i]);
		i++;
	}
	return (lower);
}

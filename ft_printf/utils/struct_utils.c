/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:02:36 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 11:19:41 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_metadata	*new_metadata(char *content)
{
	t_metadata	*new_object;

	new_object = ft_calloc(1, sizeof(t_metadata));
	if (new_object)
	{
		if (content)
			new_object->content = content;
		else
			new_object->content = NULL;
		new_object->char_counter = 0;
		new_object->curr_idx = 0;
		new_object->flags = NULL;
		new_object->conversion = (char)0;
	}
	return (new_object);
}

void	free_struct(t_metadata **metadata_ptr)
{
	if (*metadata_ptr)
	{
		if ((*metadata_ptr)->content)
			free((*metadata_ptr)->content);
		if ((*metadata_ptr)->flags)
			free((*metadata_ptr)->flags);
		(*metadata_ptr)->char_counter = 0;
		(*metadata_ptr)->curr_idx = 0;
		(*metadata_ptr)->conversion = 0;
	}
	free_and_nullify(*metadata_ptr);
}

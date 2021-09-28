/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:21:24 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/28 00:24:39 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

// Main struct

typedef struct	s_metadata
{
	char	*content;
	int		char_counter;
	int		curr_idx;
	char	*flags;
	char	conversion;
}				t_metadata;

// Struct Utils
t_metadata	*new_metadata(char *content);
void		free_struct(t_metadata **metadata_ptr);

// Handlers
void	print_handler(t_metadata *data, va_list args);
int		eval_conversions(t_metadata *data, int curr_idx);
void	handle_result(t_metadata *data, va_list args);
void	handle_string(va_list args);
void	handle_hex(va_list args, int is_upper);
void	handle_pointer(va_list args);
// Secondary Aux functions
char	*to_hex(unsigned long nbr, int is_upper);
void	free_and_nullify(void *ptr);
char	*ft_str_tolower(char *str);

// Main function
int		ft_printf(const char *str, ...);

#endif
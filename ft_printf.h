/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:21:24 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/27 05:30:38 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

// Handlers
int		eval_conversions(const char spec);
void	handle_result(char spec, va_list args);
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
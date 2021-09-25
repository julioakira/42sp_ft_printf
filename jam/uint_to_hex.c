/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:52:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/21 14:54:48 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*to_hex(unsigned int nbr);
static char	*converter(unsigned int nbr, char *buffer);
static int	digit_counter(unsigned int nbr);
static char	*str_rev(char *str);

static char	*str_rev(char *str)
{
	size_t	orig_len;
	size_t	idx;
	char	*reversed;

	idx = 0;
	orig_len = ft_strlen(str);
	reversed = ft_calloc(orig_len + 1, sizeof(char));
	if(!reversed)
		return (NULL);
	while (idx < orig_len)
	{
		reversed[idx] = str[orig_len - idx - 1];
		idx++;
	}
	free(str);
	str = NULL;
	return (reversed);
}

// Works with negative numbers, but the minus
// sign is ignored.
static int	digit_counter(unsigned int nbr)
{
	int digits;

	digits = !nbr;
	while (nbr)
	{
		digits++;
		nbr /= 10;
	}
	return (digits);
}

static char	*converter(unsigned int nbr, char *buffer)
{
	unsigned int	n;
	unsigned int	tmp;
	unsigned int	idx;
	char 			*converted;

	n = nbr;
	idx = 0;
	while (n)
	{
		tmp = n % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 55;
		buffer[idx++] = tmp;
		n /= 16;
	}
	converted = str_rev(buffer);
	return (converted);
}

// How Hexadecimal works
// https://simple.wikipedia.org/wiki/Hexadecimal
// Does not work with negative numbers.
// nbr needs to be converted to positive and write
// negative sign before calling.
char	*to_hex(unsigned int nbr)
{
	char			*result;
	int				digit_count;

	digit_count = digit_counter(nbr);
	if (digit_count <= 2)
		result = ft_calloc(digit_count + 1, sizeof(char));
	else
		result = ft_calloc(digit_count, sizeof(char));
	if (!result)
		return (NULL);
	result = converter(nbr, result);
	return (result);
}

// gcc -Werror -Wextra -Wall ./jam/uint_to_hex.c libft/libft.a && ./a.out
#include <stdio.h>
#
int main(void)
{
	unsigned int nbr = 954;
	printf("Result: %s", to_hex(nbr));
}
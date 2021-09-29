/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:52:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/29 18:40:14 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int len(unsigned long n, int base);

char *to_hex(unsigned long n, int is_upper)
{
	int l;
	char *hex;
	char *map[2];

	l = len(n, 16);
	map[0] = "0123456789abcdef";
	map[1] = "0123456789ABCDEF";
	hex = ft_calloc(l + 1, 1);
	while (l-- > 0)
	{
		hex[l] = (unsigned char)map[is_upper][(n % 16)];
		n = n / 16;
	}
	return (hex);
}

int len(unsigned long n, int base)
{
	int l;

	l = 1;
	while (n / base != 0)
	{
		l++;
		n = n / base;
	}
	return (l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:51:42 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/14 03:32:02 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	sum(int, ...);

int	sum(int num_args, ...)
{
	int		result;
	va_list	arg_list;
	int		idx;

	result = 0;
	idx = 0;
	va_start(arg_list, num_args);
	while (idx < num_args)
	{
		result += va_arg(arg_list, int);
		idx++;
	}
	va_end(arg_list);
	return (result);
}

int main(void)
{
	printf("The sum of the provided numbers is: %d\n", sum(4, 2, 3, 4, 5));
	return (0);
}
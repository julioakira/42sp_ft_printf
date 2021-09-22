/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 04:23:02 by jakira-p          #+#    #+#             */
/*   Updated: 2021/09/19 04:47:50 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


// Printf gets a variable list of arguments.
// Incase of a string, it switches the %(type) for that argument
// wherever the %(arg) is located in the string.
int	inside_string(char *str, int n)
{
	if (str && n)
	{
		printf("A string and a digit!: %s% d\n", str, n);
		printf("A string %s  and a digit!: %d\n", str, n);
		return (0);
	}
	return (1);
}

// The floating point number gets rounded
int	precision_test(float f_number)
{
	if (f_number)
	{
		printf("The provided float is: %.2f\n", f_number);
		return (1);
	}
	return (0);
}

int main(void)
{
	inside_string("**example**", 10);
	precision_test(1.24876);
	precision_test(1.2432);
	precision_test(1.2467);
	return (0);
}
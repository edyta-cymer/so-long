/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:31:46 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:31:50 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(unsigned int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	print_hexadecimal(unsigned int number, char symbol)
{
	char	*lowercased;
	char	*uppercased;
	char	*result;
	int		counter;
	int		res_int;

	lowercased = "0123456789abcdef";
	uppercased = "0123456789ABCDEF";
	counter = count_digits(number);
	result = malloc(counter * sizeof(char) + 1);
	if (!result)
		return (0);
	result[counter] = '\0';
	while (counter-- > 0)
	{
		if (symbol == 'X')
			result[counter] = uppercased[number % 16];
		else
			result[counter] = lowercased[number % 16];
		number /= 16;
	}
	res_int = ft_strlen(result);
	print_string(result);
	free(result);
	return (res_int);
}

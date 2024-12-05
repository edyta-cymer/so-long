/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:23:19 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:23:22 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > 2147483647 / size)
		return (0);
	ptr = (unsigned char *)malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

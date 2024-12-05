/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:29:38 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:29:43 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lt, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (lt[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		while (big[i + j] == lt[j] && big[i + j] && i + j < len)
		{
			j++;
			if (lt[j] == 0)
				return ((char *)big + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

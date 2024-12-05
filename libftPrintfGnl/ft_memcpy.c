/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:25:33 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:25:36 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	else
	{
		while (i < n)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
		return (ptr_dst);
	}
}

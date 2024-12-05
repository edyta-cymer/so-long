/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:27:43 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:27:46 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1);
	if (!res)
		return (0);
	while ((s1)[i])
	{
		res[i] = (s1)[i];
		i++;
	}
	while ((s2)[j])
	{
		res[i] = (s2)[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

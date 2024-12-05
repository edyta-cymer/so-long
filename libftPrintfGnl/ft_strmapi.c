/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:29:06 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:29:09 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	str = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = (*f)(i, s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

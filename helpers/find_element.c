/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:29:59 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:30:01 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	find_element(char **map, char element)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == element)
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

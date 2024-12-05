/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:53 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:24:55 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_element(char **map, char element)
{
	int	counter;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		j = 0;
		i++;
	}
	return (counter);
}

bool	is_playable(char **map)
{
	if (count_element(map, 'E') == 1
		&& count_element(map, 'P') == 1
		&& count_element(map, 'C') >= 1)
		return (true);
	return (false);
}

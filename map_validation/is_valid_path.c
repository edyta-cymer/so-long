/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:25:21 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:25:23 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map, int height, int y, int x)
{
	int	width;

	width = line_length(map[0]);
	if (y < 0 || y >= height || x < 0 || x >= width
		|| map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'X')
		return ;
	map[y][x] = 'V';
	flood_fill(map, height, y - 1, x);
	flood_fill(map, height, y + 1, x);
	flood_fill(map, height, y, x - 1);
	flood_fill(map, height, y, x + 1);
}

static char	**duplicate_map(char **original)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (map_length(original) + 1));
	if (!copy)
		return (NULL);
	copy[map_length(original)] = NULL;
	while (original[i])
	{
		copy[i] = ft_strdup(original[i]);
		i++;
	}
	return (copy);
}

bool	is_valid_path(char **map)
{
	int		height;
	char	**copy;
	int		pos[2];
	bool	found_c;
	bool	found_e;

	height = map_length(map);
	copy = duplicate_map(map);
	if (!copy)
	{
		ft_printf("Error!\nSomething is wrong with map copy");
		return (false);
	}
	find_position(copy, 'P', pos);
	flood_fill(copy, height, pos[1], pos[0]);
	found_c = find_element(copy, 'C');
	found_e = find_element(copy, 'E');
	free_map(copy);
	return (found_c && found_e);
}

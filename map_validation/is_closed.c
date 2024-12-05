/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:24:44 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:24:47 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_first_line(char **map)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

static bool	check_first_column(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_last_line(char **map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

static bool	check_last_column(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = (ft_strlen(map[0])) - 1;
	while (map[i])
	{
		if (map[i][j] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_closed(char **map)
{
	return (check_first_line(map)
		&& check_first_column(map)
		&& check_last_line(map)
		&& check_last_column(map));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:25:01 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:25:02 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_rectangular(char **map)
{
	int	i;
	int	first_line;

	i = 1;
	first_line = line_length(map[0]);
	while (map[i])
	{
		if (first_line != line_length(map[i]))
			return (false);
		i++;
	}
	return (true);
}

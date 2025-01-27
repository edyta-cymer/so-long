/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:30:27 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:30:29 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	find_position(char **map, char letter, int *pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == letter)
			{
				pos[0] = j;
				pos[1] = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

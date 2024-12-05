/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:09:26 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:09:27 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_image(t_mlx mlx, int i, int j, char **map)
{
	if (map[i][j] == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.droga, j * 50, i * 50);
	if (map[i][j] == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.wall, j * 50, i * 50);
	if (map[i][j] == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.paris, j * 50, i * 50);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(mlx.mlx,
			mlx.win, mlx.txt.dolar, j * 50, i * 50);
	if (map[i][j] == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win,
			mlx.txt.castle, j * 50, i * 50);
	if (map[i][j] == 'X')
		mlx_put_image_to_window(mlx.mlx, mlx.win,
			mlx.txt.pies, j * 50, i * 50);
}

void	render_map(char **map, t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			put_image(mlx, i, j, map);
			j++;
		}
		j = 0;
		i++;
	}
}

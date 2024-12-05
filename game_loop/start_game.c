/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:09:42 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:09:44 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*init_image(char *path, t_mlx mlx)
{
	int	size;

	size = 50;
	return (mlx_xpm_file_to_image(mlx.mlx, path, &size, &size));
}

void	init_textures(t_mlx *mlx)
{
	mlx->txt.paris = init_image("textures/paris.xpm", *mlx);
	mlx->txt.wall = init_image("textures/wall.xpm", *mlx);
	mlx->txt.droga = init_image("textures/droga.xpm", *mlx);
	mlx->txt.dolar = init_image("textures/dolar.xpm", *mlx);
	mlx->txt.castle = init_image("textures/castle.xpm", *mlx);
	mlx->txt.pies = init_image("textures/pies.xpm", *mlx);
}

void	destroy_textures(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->txt.paris);
	mlx_destroy_image(mlx->mlx, mlx->txt.droga);
	mlx_destroy_image(mlx->mlx, mlx->txt.dolar);
	mlx_destroy_image(mlx->mlx, mlx->txt.castle);
	mlx_destroy_image(mlx->mlx, mlx->txt.wall);
	mlx_destroy_image(mlx->mlx, mlx->txt.pies);
}

void	start_game(char **map)
{
	t_mlx	mlx;

	mlx.count = 0;
	mlx.map = map;
	find_exit(map, mlx.e_pos);
	find_position(mlx.map, 'P', mlx.p_pos);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx,
			line_length(map[0]) * 50,
			map_length(map) * 50,
			"so_long");
	init_textures(&mlx);
	render_map(map, mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_game, &mlx);
	mlx_loop(mlx.mlx);
}

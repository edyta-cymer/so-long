/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:18:44 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 19:18:46 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <fcntl.h>
# include <stdbool.h>
# include "libftPrintfGnl/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include "minilibx/mlx.h"
# define SO_LONG_H

typedef struct s_txt
{
	void	*paris;
	void	*wall;
	void	*droga;
	void	*dolar;
	void	*castle;
	void	*pies;
}	t_txt;

typedef struct s_mlx
{
	void	*mlx;
	void	*win; // window
	t_txt	txt; //texture
	int		p_pos[2];
	char	**map;
	int		e_pos[2];
	int		count; // moves count
}	t_mlx;

int		line_length(char *line);
int		map_length(char **map);
bool	is_playable(char **map);
bool	is_rectangular(char **map);
bool	is_closed(char **map);
bool	is_valid(char **map);
bool	is_valid_path(char **map);
int		count_coins(char **map);
void	start_game(char **map);
void	render_map(char **map, t_mlx mlx);
int		key_hook(int keycode, t_mlx *vars);
void	find_position(char **map, char letter, int *pos);
bool	find_element(char **map, char element);
void	find_exit(char **map, int pos[2]);
int		exit_game(t_mlx *vars);
void	display_moves(t_mlx *mlx, int moves);
void	destroy_textures(t_mlx *mlx);
void	free_map(char **map);

#endif

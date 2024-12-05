/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:09:09 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:09:11 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(int keycode, t_mlx *vars)
{
	if (keycode == 'w' && vars->map[vars->p_pos[1] - 1][vars->p_pos[0]] != '1')
	{
		if (vars->map[vars->p_pos[1] - 1][vars->p_pos[0]] == 'X')
			exit_game(vars);
		else if (vars->p_pos[0] == vars->e_pos[0]
			&& vars->p_pos[1] == vars->e_pos[1])
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = 'E';
			vars->map[--(vars->p_pos[1])][vars->p_pos[0]] = 'P';
			vars->count++;
		}
		else
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = '0';
			vars->map[--(vars->p_pos[1])][vars->p_pos[0]] = 'P';
			vars->count++;
		}
	}
}

static void	move_left(int keycode, t_mlx *vars)
{
	if (keycode == 'a' && vars->map[vars->p_pos[1]][vars->p_pos[0] - 1] != '1')
	{
		if (vars->map[vars->p_pos[1]][vars->p_pos[0] - 1] == 'X')
			exit_game(vars);
		if (vars->p_pos[0] == vars->e_pos[0]
			&& vars->p_pos[1] == vars->e_pos[1])
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = 'E';
			vars->map[vars->p_pos[1]][--(vars->p_pos[0])] = 'P';
			vars->count++;
		}
		else
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = '0';
			vars->map[vars->p_pos[1]][--(vars->p_pos[0])] = 'P';
			vars->count++;
		}
	}
}

static void	move_right(int keycode, t_mlx *vars)
{
	if (keycode == 'd' && vars->map[vars->p_pos[1]][vars->p_pos[0] + 1] != '1')
	{
		if (vars->map[vars->p_pos[1]][vars->p_pos[0] + 1] == 'X')
			exit_game(vars);
		if (vars->p_pos[0] == vars->e_pos[0]
			&& vars->p_pos[1] == vars->e_pos[1])
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = 'E';
			vars->map[vars->p_pos[1]][++(vars->p_pos[0])] = 'P';
			vars->count++;
		}
		else
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = '0';
			vars->map[vars->p_pos[1]][++(vars->p_pos[0])] = 'P';
			vars->count++;
		}
	}
}

static void	move_down(int keycode, t_mlx *vars)
{
	if (keycode == 's' && vars->map[vars->p_pos[1] + 1][vars->p_pos[0]] != '1')
	{
		if (vars->map[vars->p_pos[1] + 1][vars->p_pos[0]] == 'X')
			exit_game(vars);
		if (vars->p_pos[0] == vars->e_pos[0]
			&& vars->p_pos[1] == vars->e_pos[1])
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = 'E';
			vars->map[++(vars->p_pos[1])][vars->p_pos[0]] = 'P';
			vars->count++;
		}
		else
		{
			vars->map[vars->p_pos[1]][vars->p_pos[0]] = '0';
			vars->map[++(vars->p_pos[1])][vars->p_pos[0]] = 'P';
			vars->count++;
		}
	}
}

int	key_hook(int keycode, t_mlx *vars)
{
	move_up(keycode, vars);
	move_left(keycode, vars);
	move_right(keycode, vars);
	move_down(keycode, vars);
	if (vars->p_pos[0] == vars->e_pos[0]
		&& vars->p_pos[1] == vars->e_pos[1]
		&& (find_element(vars->map, 'C')))
	{
		ft_printf("count is: %i\n", vars->count);
		exit_game(vars);
	}
	if (keycode == 65307)
		exit_game(vars);
	ft_printf("count is: %i\n", vars->count);
	render_map(vars->map, *vars);
	display_moves(vars, vars->count);
	return (0);
}

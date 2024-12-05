/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:08:04 by ecymer            #+#    #+#             */
/*   Updated: 2024/10/08 20:08:06 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_moves(t_mlx *mlx, int moves)
{
	char	*str;

	str = ft_itoa(moves);
	if (!str)
		return ;
	mlx_string_put(mlx->mlx, mlx->win, 50, 35, 0x00000000, "Moves: ");
	mlx_string_put(mlx->mlx, mlx->win, 100, 35, 0x00000000, str);
	free(str);
}

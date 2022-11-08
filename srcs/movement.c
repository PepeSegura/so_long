/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:31 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/08 01:17:52 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_verify(t_map map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.height)
	{
		while (x < map.wide)
		{
			if (map.matrix[y][x] == COLLECTIBLE_CHAR)
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

void	ft_move(t_cosas *cosas, int x, int y)
{
	if (cosas->map.matrix[cosas->player.y + y][cosas->player.x + x] == EMPTY_CHAR
		|| cosas->map.matrix[cosas->player.y + y][cosas->player.x + x] == COLLECTIBLE_CHAR)
	{
		// if (cosas->map.matrix[cosas->player.y + y][cosas->player.x + x] == COLLECTIBLE_CHAR)
		// 	cosas.
		cosas->map.matrix[cosas->player.y][cosas->player.x] = EMPTY_CHAR;
		cosas->map.matrix[cosas->player.y + y][cosas->player.x + x] = PLAYER_CHAR;
		cosas->player.y+=y;
		cosas->player.x+=x;
	}
	ft_draw_background(&cosas->map, &cosas->xpm, &cosas->meta);
	ft_draw_game(&cosas->map, &cosas->xpm, &cosas->meta);
	if (ft_map_verify(cosas->map) && cosas->map.matrix[cosas->player.y + y][cosas->player.x + x] == EXIT_CHAR)
		exit(EXIT_SUCCESS);
}


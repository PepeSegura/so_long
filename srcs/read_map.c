/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:54:11 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/08 01:39:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_map *map, t_player *player, int x, int y)
{
	player->y = y;
	player->x = x;
	map->reqs.p_count++;
}

void	read_map(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->wide)
		{
			if (map->matrix[y][x] == PLAYER_CHAR)
				set_player(map, player, x, y);
			if (map->matrix[y][x] == COLLECTIBLE_CHAR)
				map->reqs.c_count++;
			if (map->matrix[y][x] == EXIT_CHAR)
				map->reqs.e_count++;
			x++;
		}
		y++;
		x = 0;
	}
	ft_printf("\nPlayer pos:\n  X:\t%d\n  Y:\t%d\n", player->x, player->y);
	ft_printf("\nMap:\n  P:\t%d\n  C:\t%d\n  E:\t%d\n",
		map->reqs.p_count, map->reqs.c_count,
		map->reqs.e_count);
}

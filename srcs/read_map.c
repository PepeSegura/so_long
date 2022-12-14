/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:54:11 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/13 04:57:46 by psegura-         ###   ########.fr       */
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
			ft_check_mid_row(map->matrix[y], map);
			x++;
		}
		y++;
		x = 0;
	}
}

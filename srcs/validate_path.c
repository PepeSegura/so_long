/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:05:45 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 01:54:10 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_replace(t_map *map, int y, int x)
{
	if (map->matrix[y - 1][x] != WALL_CHAR
		&& map->matrix[y - 1][x] != PLAYER_CHAR)
		map->matrix[y - 1][x] = PLAYER_CHAR;
	if (map->matrix[y + 1][x] != WALL_CHAR
		&& map->matrix[y + 1][x] != PLAYER_CHAR)
		map->matrix[y + 1][x] = PLAYER_CHAR;
	if (map->matrix[y][x - 1] != WALL_CHAR
		&& map->matrix[y][x - 1] != PLAYER_CHAR)
		map->matrix[y][x - 1] = PLAYER_CHAR;
	if (map->matrix[y][x + 1] != WALL_CHAR
		&& map->matrix[y][x + 1] != PLAYER_CHAR)
		map->matrix[y][x + 1] = PLAYER_CHAR;
}

void	validate_path(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->wide - 1)
		{
			if (map->matrix[y][x] == PLAYER_CHAR)
				ft_replace(map, y, x);
			x++;
		}
		ft_printf("%s", map->matrix[y]);
		y++;
	}
	y = 0;
}

void	validate_loop(t_map *map)
{
	int	i;

	i = map->wide;
	while (i--)
	{
		ft_printf("\033c");
		validate_path(map);
		usleep(75000);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:05:45 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 14:55:05 by psegura-         ###   ########.fr       */
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
		y++;
	}
	y = 0;
}

void	last_map_check(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->reqs.c_count = 0;
	map->reqs.e_count = 0;
	while (y < map->height)
	{
		while (x < map->wide)
		{
			if (map->matrix[y][x] == COLLECTIBLE_CHAR)
				map->reqs.c_count++;
			if (map->matrix[y][x] == EXIT_CHAR)
				map->reqs.e_count++;
			x++;
		}
		y++;
		x = 0;
	}
	if (map->reqs.c_count > 0 || map->reqs.e_count > 0)
		ft_print_error(INVALID_PATH, "Map error: Not a valid path");
}

void	validate_loop(t_map *map)
{
	int	i;

	i = map->wide * 5;
	while (i--)
		validate_path(map);
	last_map_check(map);
}

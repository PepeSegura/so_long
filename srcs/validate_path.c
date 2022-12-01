/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:05:45 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/01 15:50:09 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		ft_printf("%s", map->matrix[y]);
		y++;
	}
}

	// ft_printf("\033c");
	// print_map(map);
	// usleep(15000);
void	comprobar(t_map *map, int y, int x)
{
	map->matrix[y][x] = PLAYER_CHAR;
	if (map->matrix[y - 1][x] != WALL_CHAR
		&& map->matrix[y - 1][x] != PLAYER_CHAR)
		comprobar(map, y - 1, x);
	if (map->matrix[y + 1][x] != WALL_CHAR
		&& map->matrix[y + 1][x] != PLAYER_CHAR)
		comprobar(map, y + 1, x);
	if (map->matrix[y][x - 1] != WALL_CHAR
		&& map->matrix[y][x - 1] != PLAYER_CHAR)
		comprobar(map, y, x - 1);
	if (map->matrix[y][x + 1] != WALL_CHAR
		&& map->matrix[y][x + 1] != PLAYER_CHAR)
		comprobar(map, y, x + 1);
}

void	find_player(t_map *map, int *y, int *x)
{
	*y = 0;
	while (*y < map->height)
	{
		*x = 0;
		while (*x < map->wide - 1)
		{
			if (map->matrix[*y][*x] == PLAYER_CHAR)
				return ;
			(*x)++;
		}
		(*y)++;
	}
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
	int	x;
	int	y;

	find_player(map, &y, &x);
	comprobar(map, y, x);
	last_map_check(map);
}

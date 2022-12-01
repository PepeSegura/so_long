/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:15 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/29 12:48:27 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_map *map, t_xpm *xpm, t_meta *meta, t_count *c)
{
	if (map->matrix[c->i][c->j] == WALL_CHAR)
		mlx_put_image_to_window(meta->mlx, meta->mlx_win,
			xpm->wall, c->j * XPM_SIZE, c->i * XPM_SIZE);
	if (map->matrix[c->i][c->j] == COLLECTIBLE_CHAR)
		mlx_put_image_to_window(meta->mlx, meta->mlx_win,
			xpm->collectiblle, c->j * XPM_SIZE, c->i * XPM_SIZE);
	if (map->matrix[c->i][c->j] == EXIT_CHAR)
		mlx_put_image_to_window(meta->mlx, meta->mlx_win,
			xpm->exit, c->j * XPM_SIZE, c->i * XPM_SIZE);
	if (map->matrix[c->i][c->j] == PLAYER_CHAR)
		mlx_put_image_to_window(meta->mlx, meta->mlx_win,
			xpm->player, c->j * XPM_SIZE, c->i * XPM_SIZE);
	if (map->matrix[c->i][c->j] == ENEMIE_CHAR)
		mlx_put_image_to_window(meta->mlx, meta->mlx_win,
			xpm->enemy, c->j * XPM_SIZE, c->i * XPM_SIZE);
}

void	ft_draw_background(t_map *map, t_xpm *xpm, t_meta *meta)
{
	t_count	c;

	ft_memset(&c, 0, sizeof(t_count));
	while (c.i < map->height)
	{
		while (c.j < map->wide)
		{
			mlx_put_image_to_window(meta->mlx, meta->mlx_win,
				xpm->empty, c.j * XPM_SIZE, c.i * XPM_SIZE);
			c.j++;
		}
		c.i++;
		c.j = 0;
	}
}

void	ft_draw_game(t_map *map, t_xpm *xpm, t_meta *meta)
{
	t_count	c;

	ft_memset(&c, 0, sizeof(t_count));
	while (c.i < map->height)
	{
		while (c.j < map->wide)
		{
			ft_draw(map, xpm, meta, &c);
			c.j++;
		}
		c.i++;
		c.j = 0;
	}	
}

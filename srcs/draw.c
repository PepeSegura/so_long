/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:15 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/07 12:14:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_images(t_meta *meta, t_xpm *xpm)
{
	xpm->empty = mlx_xpm_file_to_image(meta->mlx, EMPTY_PATH,
			&meta->img_w, &meta->img_h);
	xpm->wall = mlx_xpm_file_to_image(meta->mlx, WALL_PATH,
			&meta->img_w, &meta->img_h);
	xpm->collectiblle = mlx_xpm_file_to_image(meta->mlx, COLLECTIBLE_PATH,
			&meta->img_w, &meta->img_h);
	xpm->exit = mlx_xpm_file_to_image(meta->mlx, EXIT_PATH,
			&meta->img_w, &meta->img_h);
	xpm->player = mlx_xpm_file_to_image(meta->mlx, PLAYER_PATH,
			&meta->img_w, &meta->img_h);
}

//Imprimir fondo de EMPTY_CHAR
void	ft_draw_background(t_map *map, t_xpm *xpm, t_meta *meta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->wide)
		{
			mlx_put_image_to_window(meta->mlx, meta->mlx_win,
				xpm->empty, j * XPM_SIZE, i * XPM_SIZE);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_draw_game(t_map *map, t_xpm *xpm, t_meta *meta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->wide)
		{
			if (map->matrix[i][j] == WALL_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					xpm->wall, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == COLLECTIBLE_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					xpm->collectiblle, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == EXIT_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					xpm->exit, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == PLAYER_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					xpm->player, j * XPM_SIZE, i * XPM_SIZE);
			j++;
		}
		ft_printf("%s", map->matrix[i]);
		i++;
		j = 0;
	}	
}

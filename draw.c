/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:15 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/25 16:54:33 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

//Imprimir fondo de EMPTY_CHAR
void	ft_draw_background(t_map *map, t_img *img, t_meta *meta)
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
				img->xpm_empty, j * XPM_SIZE, i * XPM_SIZE);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_draw_game(t_map *map, t_img *img, t_meta *meta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->wide)
		{
			// if (map->matrix[i][j] == EMPTY_CHAR)
			// 	mlx_put_image_to_window(meta->mlx, meta->mlx_win,
			// 		img->xpm_empty, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == WALL_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					img->xpm_wall, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == COLLECTIBLE_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					img->xpm_collectiblle, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == EXIT_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					img->xpm_exit, j * XPM_SIZE, i * XPM_SIZE);
			if (map->matrix[i][j] == PLAYER_CHAR)
				mlx_put_image_to_window(meta->mlx, meta->mlx_win,
					img->xpm_player, j * XPM_SIZE, i * XPM_SIZE);
			printf("%c", map->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}	
}

// void	ft_draw_player(t_map *map, t_img *img, t_meta *meta, t_player *p)
// {
// 	mlx_put_image_to_window(meta->mlx, meta->mlx_win,
// 			img->xpm_player, j * XPM_SIZE, i * XPM_SIZE);
// }
// 			ft_draw_game(&map, &draw, &meta);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:54:48 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/10 18:55:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./include/so_long.h"

// void	ft_draw_background(t_map *map, t_img *img, t_meta *meta)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	//Imprimir fondo de EMPTY_CHAR
// 	while (i < map->height)
// 	{
// 		while (j < map->wide)
// 		{
// 			mlx_put_image_to_window(meta->mlx, meta->mlx_win,
// 				img->xpm_empty, j * XPM_SIZE, i * XPM_SIZE);
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// }

// void	ft_draw_game(t_map *map, t_img *img, t_meta *meta)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < map.height)
// 	{
// 		while (j < map.wide)
// 		{
// 			if (map.matrix[i][j] == EMPTY_CHAR)
// 				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_empty, j * XPM_SIZE, i * XPM_SIZE);
// 			if (map.matrix[i][j] == WALL_CHAR)
// 				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_wall, j * XPM_SIZE, i * XPM_SIZE);
// 			if (map.matrix[i][j] == COLLECTIBLE_CHAR)
// 				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_collectiblle, j * XPM_SIZE, i * XPM_SIZE);
// 			if (map.matrix[i][j] == EXIT_CHAR)
// 				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_exit, j * XPM_SIZE, i * XPM_SIZE);
// 			if (map.matrix[i][j] == PLAYER_CHAR)
// 				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_player, j * XPM_SIZE, i * XPM_SIZE);
// 			printf("%c", map.matrix[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 		j = 0;
// 	}	
// }

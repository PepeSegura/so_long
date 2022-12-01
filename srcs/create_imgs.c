/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:58:23 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/29 15:03:57 by psegura-         ###   ########.fr       */
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
	xpm->enemy = mlx_xpm_file_to_image(meta->mlx, ENEMIE_PATH,
			&meta->img_w, &meta->img_h);
	if (xpm->empty == NULL || xpm->wall == NULL || xpm->collectiblle == NULL
		|| xpm->exit == NULL || xpm->player == NULL || xpm->enemy == NULL )
		ft_print_error(INVALID_FD, "Map error: Cannot load Sprites");
}

void	ft_create_images_player(t_meta *meta, t_xpm *xpm, char *path)
{
	xpm->player = mlx_xpm_file_to_image(meta->mlx, path,
			&meta->img_w, &meta->img_h);
	if (xpm->player == NULL)
		ft_print_error(INVALID_FD, "Map error: Cannot load Sprites");
}

void	ft_create_images_exit(t_meta *meta, t_xpm *xpm, char *path)
{
	xpm->exit = mlx_xpm_file_to_image(meta->mlx, path,
			&meta->img_w, &meta->img_h);
	if (xpm->exit == NULL)
		ft_print_error(INVALID_FD, "Map error: Cannot load Sprites");
}

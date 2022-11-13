/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:58:23 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/13 06:58:53 by psegura-         ###   ########.fr       */
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
	xpm->enemie = mlx_xpm_file_to_image(meta->mlx, ENEMIE_PATH,
			&meta->img_w, &meta->img_h);
}

void	ft_create_images_player(t_meta *meta, t_xpm *xpm, char *path)
{
	xpm->player = mlx_xpm_file_to_image(meta->mlx, path,
			&meta->img_w, &meta->img_h);
}

void	ft_create_images_exit(t_meta *meta, t_xpm *xpm, char *path)
{
	xpm->exit = mlx_xpm_file_to_image(meta->mlx, path,
			&meta->img_w, &meta->img_h);
}

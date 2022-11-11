/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:21:47 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/11 03:59:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int keycode, t_cosas *cosas)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == W || keycode == UP)
	{
		ft_create_images_player(&cosas->meta, &cosas->xpm, PLAYER_UP);
		ft_move(cosas, 0, -1);
	}
	if (keycode == A || keycode == LEFT)
	{
		ft_create_images_player(&cosas->meta, &cosas->xpm, PLAYER_LEFT);
		ft_move(cosas, -1, 0);
	}
	if (keycode == S || keycode == DOWN)
	{
		ft_create_images_player(&cosas->meta, &cosas->xpm, PLAYER_DOWN);
		ft_move(cosas, 0, 1);
	}
	if (keycode == D || keycode == RIGHT)
	{
		ft_create_images_player(&cosas->meta, &cosas->xpm, PLAYER_RIGHT);
		ft_move(cosas, 1, 0);
	}
	return (0);
}

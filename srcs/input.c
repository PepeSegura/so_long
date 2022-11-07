/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:21:47 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/02 15:54:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int keycode, t_meta *meta)
{
	int	jaja;

	jaja = meta->x;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == W || keycode == UP)
		printf("Arriba\n");
	if (keycode == A || keycode == LEFT)
		printf("Izquierda\n");
	if (keycode == S || keycode == DOWN)
		printf("Abajo\n");
	if (keycode == D || keycode == RIGHT)
		printf("Derecha\n");
	return (0);
}

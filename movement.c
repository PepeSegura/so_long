/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:31 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/10 16:50:17 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"


int	ft_input(int keycode, t_meta *meta)
{
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

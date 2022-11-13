/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:31 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/13 06:32:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_cosas *c, int x, int y)
{
	if (c->map.matrix[c->p.y + y][c->p.x + x] == ENEMIE_CHAR)
		ft_print_error(DEAD, "Buggy killed you :(");
	if (c->map.reqs.c_count == 0
		&& c->map.matrix[c->p.y + y][c->p.x + x] == EXIT_CHAR)
		ft_print_error(WIN, "You found the one piece!");
	if (c->map.matrix[c->p.y + y][c->p.x + x] == EMPTY_CHAR
		|| c->map.matrix[c->p.y + y][c->p.x + x] == COLLECTIBLE_CHAR)
	{
		if (c->map.matrix[c->p.y + y][c->p.x + x] == COLLECTIBLE_CHAR)
			c->map.reqs.c_count--;
		c->map.matrix[c->p.y][c->p.x] = EMPTY_CHAR;
		c->map.matrix[c->p.y + y][c->p.x + x] = PLAYER_CHAR;
		c->p.y += y;
		c->p.x += x;
		c->moves_count++;
		ft_printf("\033cMoves Counter: %d\n", c->moves_count);
	}
	ft_draw_background(&c->map, &c->xpm, &c->meta);
	ft_draw_game(&c->map, &c->xpm, &c->meta);
	if (c->map.reqs.c_count == 0)
		ft_create_images_exit(&c->meta, &c->xpm, EXIT_OPEN_PATH);
}

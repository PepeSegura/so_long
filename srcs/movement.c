/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:31 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/15 15:21:00 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_interface(t_cosas *c)
{
	ft_printf("\033c");
	ft_printf("\033c\033[0;94mMoves Counter:\n\033[0;96m%d\n\n", c->moves_count);
	ft_printf("\033[0;94mFruit left:\n\033[0;96m%d\n\n", c->map.reqs.c_count);
	ft_printf("\033[0;94mCan You exit?\n");
	if (c->map.reqs.c_count > 0)
		ft_printf("\033[0;96mNO\n\n");
	if (c->map.reqs.c_count == 0)
		ft_printf("\033[0;96mYES\n\n");
	mlx_string_put(c->meta.mlx, c->meta.mlx_win,
		(c->meta.win_w / 2) - 50, 10, TEXT_COLOR, "Moves Count");
	mlx_string_put(c->meta.mlx, c->meta.mlx_win,
		(c->meta.win_w / 2), 27, NUMBER_COLOR, ft_itoa(c->moves_count));
}

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
		if (c->map.reqs.c_count == 0)
			ft_create_images_exit(&c->meta, &c->xpm, EXIT_OPEN_PATH);
		c->moves_count++;
	}
	ft_draw_background(&c->map, &c->xpm, &c->meta);
	ft_draw_game(&c->map, &c->xpm, &c->meta);
	ft_print_interface(c);
}

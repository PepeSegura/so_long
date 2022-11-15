/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/15 17:10:10 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_cosas		c;
	t_map		map_cpy;
	char		*file;

	file = "pepex is my next project :P";
	if (argc != 2)
		file = ft_map_selector(file);
	if (argc == 2)
		file = argv[1];
	ft_init(&c, &map_cpy, file);
	c.meta.mlx = mlx_init();
	c.meta.mlx_win = mlx_new_window(
			c.meta.mlx, c.meta.win_w, c.meta.win_h, "so_long");
	c.img.img = mlx_new_image(c.meta.mlx, c.meta.win_w, c.meta.win_h);
	ft_create_images(&c.meta, &c.xpm);
	ft_draw_background(&c.map, &c.xpm, &c.meta);
	ft_draw_game(&c.map, &c.xpm, &c.meta);
	ft_print_interface(&c);
	mlx_key_hook(c.meta.mlx_win, ft_input, &c);
	mlx_hook(c.meta.mlx_win, DESTROY, 0, ft_exit, &c.meta);
	mlx_loop(c.meta.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 03:12:38 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	t_cosas		c;
	t_map		map_cpy;
	char		*file;

	if (argc != 2)
		return (0);
	file = argv[1];
	// ft_game_init(&c, &map_cpy, file);
	ft_memset(&c, 0, sizeof(t_cosas));
	ft_memset(&map_cpy, 0, sizeof(t_map));
	ft_get_map_size(ft_open_map(argv[1]), &c.map);
	ft_get_map_size(ft_open_map(argv[1]), &map_cpy);
	c.map.matrix = ft_store_map(ft_open_map(argv[1]), &c.map);
	map_cpy.matrix = ft_store_map(ft_open_map(argv[1]), &map_cpy);
	read_map(&c.p, &c.map);
	read_map(&c.p, &map_cpy);
	ft_valid_map(&c);
	validate_loop(&map_cpy);
	c.meta.win_w = c.map.wide * XPM_SIZE;
	c.meta.win_h = c.map.height * XPM_SIZE;
	c.meta.mlx = mlx_init();
	c.meta.mlx_win = mlx_new_window(
			c.meta.mlx, c.meta.win_w, c.meta.win_h, "so_long");
	c.img.img = mlx_new_image(c.meta.mlx, c.meta.win_w, c.meta.win_h);
	ft_create_images(&c.meta, &c.xpm);
	ft_draw_background(&c.map, &c.xpm, &c.meta);
	ft_draw_game(&c.map, &c.xpm, &c.meta);
	mlx_key_hook(c.meta.mlx_win, ft_input, &c);
	mlx_hook(c.meta.mlx_win, ON_DESTROY, 0, ft_input, &c.meta);
	mlx_loop(c.meta.mlx);
	ft_leaks();
	return (0);
}

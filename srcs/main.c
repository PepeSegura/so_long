/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/07 19:31:14 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	t_meta		meta;
	t_data		img;
	t_map		map;
	t_xpm		xpm;
	t_player	player;
	
	if (argc != 2)
	{
		ft_printf("Argumentos invalidos\n");
		return (0);
	}
	//Get MAPA size
	ft_get_map_size(ft_open_map(argv[1]), &map);
	
	//Store MAPA into matrix
	map.matrix = ft_store_map(ft_open_map(argv[1]), &map);
	ft_printf("\nMap size:\n  X:\t%d\n  Y:\t%d\n", map.wide, map.height);
	
	//Read MAPA
	read_map(&player, &map);
	
	//Get WINDOW size
	meta.win_w = map.wide * XPM_SIZE;
	meta.win_h = map.height * XPM_SIZE;
	ft_printf("\nWindow:\n  X:\t%d\n  Y:\t%d\n\n", meta.win_w, meta.win_h);
	
	//Start Mlx
	meta.mlx = mlx_init();
	//Create Window	
	meta.mlx_win = mlx_new_window(meta.mlx, meta.win_w, meta.win_h, "so_long");
	//Background Color
	img.img = mlx_new_image(meta.mlx, meta.win_w, meta.win_h);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//Sprite
	ft_create_images(&meta, &xpm);

	//Imprimir fondo de EMPTY_CHAR
	ft_draw_background(&map, &xpm, &meta);

	//Sprite
	ft_draw_game(&map, &xpm, &meta);
	
	//Hook Keypress
	mlx_key_hook(meta.mlx_win, ft_input, &meta);
	mlx_loop(meta.mlx);
	ft_leaks();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/08 01:33:15 by psegura-         ###   ########.fr       */
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
	t_xpm		xpm;
	t_player	player;
	t_cosas		cosas;
	
	if (argc != 2)
	{
		ft_printf("Argumentos invalidos\n");
		return (0);
	}
	//Get MAPA size
	ft_get_map_size(ft_open_map(argv[1]), &cosas.map);
	
	//Store MAPA into matrix
	cosas.map.matrix = ft_store_map(ft_open_map(argv[1]), &cosas.map);
	ft_printf("\nMap size:\n  X:\t%d\n  Y:\t%d\n", cosas.map.wide, cosas.map.height);
	
	//Read MAPA
	read_map(&player, &cosas.map);
	
	//Get WINDOW size
	meta.win_w = cosas.map.wide * XPM_SIZE;
	meta.win_h = cosas.map.height * XPM_SIZE;
	ft_printf("\nWindow:\n  X:\t%d\n  Y:\t%d\n\n", meta.win_w, meta.win_h);
	
	//Start Mlx
	meta.mlx = mlx_init();
	//Create Window	
	meta.mlx_win = mlx_new_window(meta.mlx, meta.win_w, meta.win_h, "so_long");
	//Background Color
	img.img = mlx_new_image(meta.mlx, meta.win_w, meta.win_h);
	//Sprite
	ft_create_images(&meta, &xpm);

	//Imprimir fondo de EMPTY_CHAR
	ft_draw_background(&cosas.map, &xpm, &meta);

	//Sprite
	ft_draw_game(&cosas.map, &xpm, &meta);
	
	cosas.player = player;
	cosas.meta = meta;
	cosas.xpm = xpm;

	//Hook Keypress
	mlx_key_hook(meta.mlx_win, ft_input, &cosas);
	mlx_loop(meta.mlx);
	ft_leaks();
	return (0);
}

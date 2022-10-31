/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/27 18:18:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	t_meta	meta;
	t_data	img;
	t_map	map;
	t_img	draw;
	// int	i = 0;
	// int	j = 0;

	meta.x = 0;
	meta.y = 0;

	if (argc != 2)
	{
		printf("Argumentos invalidos\n");
		return (0);
	}
	//Get MAPA size
	ft_get_map_size(ft_open_map(argv[1]), &map);
	//Store MAPA into matrix
	map.matrix = ft_store_map(ft_open_map(argv[1]), &map);
	printf("Map wide -> %d\n", map.wide);
	printf("Map height -> %d\n", map.height);
	//Get WINDOW size
	meta.win_w = map.wide * XPM_SIZE;
	meta.win_h = map.height * XPM_SIZE;
	printf("Window wide -> %d\n", meta.win_w);
	printf("Window height -> %d\n", meta.win_h);
	
	//Start Mlx
	meta.mlx = mlx_init();
	//Create Window	
	meta.mlx_win = mlx_new_window(meta.mlx, meta.win_w, meta.win_h, "so_long");
	//Background Color
	img.img = mlx_new_image(meta.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//Sprite
	// xpm_wall = mlx_xpm_file_to_image(meta.mlx, relative_path, &meta.img_w, &meta.img_h);
	draw.xpm_empty = mlx_xpm_file_to_image(meta.mlx, EMPTY_PATH, &meta.img_w, &meta.img_h);
	printf("%d and %d\n", meta.img_h, meta.img_w);
	draw.xpm_wall = mlx_xpm_file_to_image(meta.mlx, WALL_PATH, &meta.img_w, &meta.img_h);
	draw.xpm_collectiblle = mlx_xpm_file_to_image(meta.mlx, COLLECTIBLE_PATH, &meta.img_w, &meta.img_h);
	draw.xpm_exit = mlx_xpm_file_to_image(meta.mlx, EXIT_PATH, &meta.img_w, &meta.img_h);
	draw.xpm_player = mlx_xpm_file_to_image(meta.mlx, PLAYER_PATH, &meta.img_w, &meta.img_h);
	
	//Imprimir fondo de EMPTY_CHAR
	ft_draw_background(&map, &draw, &meta);

	//Sprite
	ft_draw_game(&map, &draw, &meta);
	
	//Hook Keypress
	mlx_key_hook(meta.mlx_win, ft_input, &meta);
	mlx_loop(meta.mlx);
	ft_leaks();
	return (0);
}

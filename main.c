/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/10 16:30:05 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

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
	int	i = 0;
	int	j = 0;

	// void	*xpm_circulo;
	// char	*relative_path = "./sprites/xpm/circulo50.xpm";

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
	draw.xpm_wall = mlx_xpm_file_to_image(meta.mlx, WALL_PATH, &meta.img_w, &meta.img_h);
	draw.xpm_collectiblle = mlx_xpm_file_to_image(meta.mlx, COLLECTIBLE_PATH, &meta.img_w, &meta.img_h);
	draw.xpm_exit = mlx_xpm_file_to_image(meta.mlx, EXIT_PATH, &meta.img_w, &meta.img_h);
	draw.xpm_player = mlx_xpm_file_to_image(meta.mlx, PLAYER_PATH, &meta.img_w, &meta.img_h);
	//Background Color
	// while (meta.y < meta.win_h)
	// {
	// 	while (meta.x < meta.win_w)
	// 	{
	// 		my_mlx_pixel_put(&img, meta.x, meta.y, 0x00755338);
	// 		meta.x++;
	// 	}
	//  	meta.x = 0;
	//  	meta.y++;
	// }
	//Background
	// mlx_put_image_to_window(meta.mlx, meta.mlx_win, img.img, 0, 0);
	
	//Imprimir fondo de EMPTY_CHAR
	while (i < map.height)
	{
		while (j < map.wide)
		{
			mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_empty, j * XPM_SIZE, i * XPM_SIZE);
			j++;
		}
		i++;
		j = 0;
	}

	//Sprite
	i = 0;
	j = 0;
	while (i < map.height)
	{
		while (j < map.wide)
		{
			if (map.matrix[i][j] == EMPTY_CHAR)
				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_empty, j * XPM_SIZE, i * XPM_SIZE);
			if (map.matrix[i][j] == WALL_CHAR)
				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_wall, j * XPM_SIZE, i * XPM_SIZE);
			if (map.matrix[i][j] == COLLECTIBLE_CHAR)
				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_collectiblle, j * XPM_SIZE, i * XPM_SIZE);
			if (map.matrix[i][j] == EXIT_CHAR)
				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_exit, j * XPM_SIZE, i * XPM_SIZE);
			if (map.matrix[i][j] == PLAYER_CHAR)
				mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_player, j * XPM_SIZE, i * XPM_SIZE);
			printf("%c", map.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	// mlx_put_image_to_window(meta.mlx, meta.mlx_win, draw.xpm_wall, 0, 0);
	//Hook Keypress
	mlx_key_hook(meta.mlx_win, ft_input, &meta);
	mlx_loop(meta.mlx);
	ft_leaks();
	return (0);
}

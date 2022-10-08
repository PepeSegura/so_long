/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/08 19:37:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

void

int	main(int argc, char **argv)
{
	t_meta	meta;
	t_data	img;
	t_map	map;

	void	*xpm_circulo;
	char	*relative_path = "./sprites/xpm/circulo50.xpm";

	meta.x = 0;
	meta.y = 0;

	if (argc != 2)
		printf("Argumentos invalidos\n");
	//Get MAPA size
	ft_get_map_size(ft_open_map(argv[1]), &map);
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
	meta.mlx_win = mlx_new_window(meta.mlx, meta.win_w, meta.win_h, "Titulo de la ventana");
	//Background Color
	img.img = mlx_new_image(meta.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//Sprite
	xpm_circulo = mlx_xpm_file_to_image(meta.mlx, relative_path, &meta.img_w, &meta.img_h);
	//Background Color
	while (meta.y < meta.win_h)
	{
		while (meta.x < meta.win_w)
		{
			my_mlx_pixel_put(&img, meta.x, meta.y, 0x000000F0);
			meta.x++;
		}
	 	meta.x = 0;
	 	meta.y++;
	}
	//Sprite
	mlx_put_image_to_window(meta.mlx, meta.mlx_win, img.img, 0, 0);
	//Background
	mlx_put_image_to_window(meta.mlx, meta.mlx_win, xpm_circulo, 0, 0);
	//Hook Keypress
	mlx_key_hook(meta.mlx_win, close_win, &meta.mlx_win);
	mlx_loop(meta.mlx);
}

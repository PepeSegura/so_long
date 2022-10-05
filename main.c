/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:23:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/05 18:51:57 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		map_wide;
	int		map_height;

	x = 0;
	y = 0;

	map_wide = ft_map_wide();
	map_height = ft_map_height();
	if (ft_valid_lines() == -1)
		return (0);
	printf("\nMap is %d pixels wide", map_wide);
	printf("\nMap is %d pixels ", map_height);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Titulo de la ventana");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y < 1080)
	{
		while (x < 1920)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
	 	x = 0;
	 	y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, close_win, &mlx_win);
	// mlx_loop(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:35 by psegura-          #+#    #+#             */
/*   Updated: 2022/09/30 13:14:33 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
//Open
# include <fcntl.h>

//Get_next_line
# include "get_next_line_bonus.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

//Leaks
void	ft_leaks(void);

//Funciones
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_win(int keycode);


//Map Validator
int	ft_map_height(void);
int	ft_map_wide(void);
int	ft_line_lenght(char *line);

#endif

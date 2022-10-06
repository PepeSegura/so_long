/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:35 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/06 03:37:25 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Header files
# include "so_long.h"
# include "libs.h"
# include "define.h"
# include "structures.h"

//Get_next_line
# include "get_next_line_bonus.h"

//Leaks
void	ft_leaks(void);

//Funciones MLX
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_win(int keycode);

//Funciones Auxiliares
char	*ft_strdup(const char *s1);

//Map Validator
int		ft_valid_map(void);
int		ft_map_height(int fd);
int		ft_map_wide(void);
int		ft_line_lenght(char *line);
int		ft_valid_lines(void);

#endif

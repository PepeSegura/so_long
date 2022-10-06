/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:35 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/06 13:09:59 by psegura-         ###   ########.fr       */
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

//Open & Store Map
int		ft_open_map(char *path);
int		ft_get_map_size(int fd, t_map *map);
//Map Validator
int		ft_line_lenght(char *line);
void	ft_valid_lines(t_map *map);
void	ft_print_error(int error_code, char *error_message);

#endif

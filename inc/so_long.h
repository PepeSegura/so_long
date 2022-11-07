/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:35 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/07 19:16:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Header files
# include "so_long.h"
# include "libs.h"
# include "define.h"
# include "structures.h"

//Libft
# include "../libft/inc/libft.h"

//Leaks
void	ft_leaks(void);

//Funciones MLX
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


//Funciones Auxiliares
char	*ft_strdup(const char *s1);

//Open & Store Map
int		ft_open_map(char *path);
int		ft_get_map_size(int fd, t_map *map);
char	**ft_store_map(int fd, t_map *map);

//Map Validator
void	read_map(t_player *player, t_map *map);
void	set_player(t_map *map, t_player *player, int x, int y);
int		ft_line_lenght(char *line);
void	ft_valid_lines(t_map *map);
void	ft_print_error(int error_code, char *error_message);

//Input & movement
int	ft_input(int keycode, t_meta *meta);

//Draw
void	ft_create_images(t_meta *meta, t_xpm *xpm);
void	ft_draw_background(t_map *map, t_xpm *xpm, t_meta *meta);
void	ft_draw_game(t_map *map, t_xpm *xpm, t_meta *meta);
void	ft_draw_player(t_map *map, t_xpm *xpm, t_meta *meta);

#endif

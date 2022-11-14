/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:35 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 03:11:46 by psegura-         ###   ########.fr       */
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
void	ft_game_init(t_cosas c, t_map map_cpy, char *file);
int		ft_open_map(char *path);
int		ft_get_map_size(int fd, t_map *map);
char	**ft_store_map(int fd, t_map *map);

//Map Validator
void	read_map(t_player *player, t_map *map);
void	ft_check_mid_row(char *row, t_map *map);
void	set_player(t_map *map, t_player *player, int x, int y);
int		ft_line_lenght(char *line);
void	validate_path(t_map *map_cpy);
void	validate_loop(t_map *map_cpy);
void	ft_valid_map(t_cosas *c);
void	ft_print_error(int error_code, char *error_message);

//Input & movement
int		ft_input(int keycode, t_cosas *cosas);
void	ft_move(t_cosas *cosas, int x, int y);

//Draw
void	ft_create_images(t_meta *meta, t_xpm *xpm);
void	ft_draw_background(t_map *map, t_xpm *xpm, t_meta *meta);
void	ft_draw_game(t_map *map, t_xpm *xpm, t_meta *meta);
void	ft_draw_player(t_map *map, t_xpm *xpm, t_meta *meta);
void	ft_create_images_player(t_meta *meta, t_xpm *xpm, char *path);
void	ft_create_images_exit(t_meta *meta, t_xpm *xpm, char *path);

#endif

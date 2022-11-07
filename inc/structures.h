/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:36:31 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/07 19:24:15 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//Map requiriments
typedef struct s_reqs {
	int		c_count;
	int		e_count;
	int		p_count;
}	t_reqs;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

//Map & data map
typedef struct s_map {	
	char	**matrix;
	int		wide;
	int		height;
	t_reqs	reqs;
}	t_map;

//Player
typedef struct s_player {
	int		x;
	int		y;
}	t_player;

//Meta
typedef struct s_meta {
	void	*mlx;
	void	*mlx_win;
	int		img_w;
	int		img_h;
	int		x;
	int		y;
	int		win_w;
	int		win_h;
}	t_meta;

//Sprites
typedef struct s_xpm {
	void	*empty;
	void	*wall;
	void	*collectiblle;
	void	*exit;
	void	*player;
}	t_xpm;

#endif

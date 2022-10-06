/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:36:31 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/06 03:42:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_size {
	int		x;
	int		y;
	
}	t_size;

//Map & data map
typedef struct s_map {	
	char	**matrix;
	int		wide;
	int		height;
	t_size	size;
}	t_map;

//Map requiriments
typedef struct s_requiriments {
	int		wide;
	int		height;
	// char	
}	t_requiriments;

#endif

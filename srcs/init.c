/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:02:47 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 14:49:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_cosas *c, t_map *map_cpy, char *file)
{
	ft_memset(c, 0, sizeof(t_cosas));
	ft_memset(map_cpy, 0, sizeof(t_map));
	ft_get_map_size(ft_open_map(file), &c->map);
	ft_get_map_size(ft_open_map(file), map_cpy);
	c->map.matrix = ft_store_map(ft_open_map(file), &c->map);
	map_cpy->matrix = ft_store_map(ft_open_map(file), map_cpy);
	read_map(&c->p, &c->map);
	read_map(&c->p, map_cpy);
	ft_valid_map(c);
	validate_loop(map_cpy);
	c->meta.win_w = c->map.wide * XPM_SIZE;
	c->meta.win_h = c->map.height * XPM_SIZE;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:02:47 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 03:16:26 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_cosas c, t_map map_cpy, char *file)
{
	ft_memset(&c, 0, sizeof(t_cosas));
	ft_memset(&map_cpy, 0, sizeof(t_map));
	ft_get_map_size(ft_open_map(file), &c.map);
	ft_get_map_size(ft_open_map(file), &map_cpy);
}

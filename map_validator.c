/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:41 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/06 13:14:30 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_valid_lines(t_map *map)
{
	if (map->wide == map->height)
		ft_print_error(SQUARE_MAP, "Map error: The map is not rectangular");
}

void	ft_print_error(int error_code, char *error_message)
{
		printf("Error\nError code:%d\t%s", error_code, error_message);
}

// int	main(int argc, char **argv)
// {
// 	t_map	map;
// 	int		i;

// 	i = 0;
// 	if (argc != 2)
// 		printf("Argumentos invalidos");
// 	ft_get_map_size(ft_open_map(argv[1]), &map);
// 	ft_valid_lines(&map);
// 	return (0);
// }
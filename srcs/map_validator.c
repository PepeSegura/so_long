/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:41 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/06 02:32:33 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_lines(t_map *map)
{
	if (map->wide == map->height)
		ft_print_error(SQUARE_MAP, "Map error: The map is not rectangular");
}

void	ft_print_error(int error_code, char *error_message)
{
		printf("Error\nError code:%d\t%s", error_code, error_message);
}

int	ft_check_map(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == EMPTY_CHAR || str[i] == WALL_CHAR
			|| str[i] == COLLECTIBLE_CHAR || str[i] == EXIT_CHAR
			|| str[i] == PLAYER_CHAR)
			check = 1;
		else
		{
			check = 0;
			return (check);
		}
		i++;
	}
	return (check);
}



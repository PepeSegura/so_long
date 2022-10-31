/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:41 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/31 00:51:03 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_valid_lines(t_map *map)
{
	if (map->wide == map->height)
		ft_print_error(SQUARE_MAP, "Map error: The map is not rectangular");
}

void	ft_print_error(int error_code, char *error_message)
{
		printf("Error\nError code:%d\t%s", error_code, error_message);
}

// int	ft_check_map(t_map *map, t_requiriments *requiriments)
// {
// }

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

// int	main(int argc, char **argv)
// {
// 	t_map	map;
// 	int		i;

// 	i = 0;
// 	if (argc != 2)
// 		printf("Argumentos invalidos\n");
// 	ft_get_map_size(ft_open_map(argv[1]), &map);
// 	ft_valid_lines(&map);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str = "10CPE10";

// 	printf("%d", ft_check_map(str));
// }

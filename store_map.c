/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:09:36 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/25 16:54:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

static char	**ft_free(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return (NULL);
}

int	ft_open_map(char *path)
{
	return (open(path, O_RDONLY));
}

int	ft_get_map_size(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		map->wide = ft_line_lenght(line);
		map->height++;
	}
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			map->height++;
			if (map->wide != ft_line_lenght(line))
			{
				printf("Map Invalid\n");
				return (INVALID_MAP);
			}
			free(line);
		}
	}
	close(fd);
	return (0);
}

char	**ft_store_map(int fd, t_map *map)
{
	int		i;

	map->matrix = (char **)malloc(sizeof(char **) * map->height + 1);
	if (!map->matrix)
		return (NULL);
	map->matrix[map->height] = NULL;
	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = get_next_line(fd);
		if (!map->matrix[i])
			return (ft_free(map->matrix, i));
		i++;
	}
	close(fd);
	return (map->matrix);
}

// int	main(int argc, char **argv)
// {
// 	t_map	map;
// 	int		i;

// 	i = 0;
// 	if (argc != 2)
// 		printf("Argumentos invalidos");
// 	ft_get_map_size(ft_open_map(argv[1]), &map);
// 	printf("Map wide -> %d\n", map.wide);
// 	printf("Map height -> %d\n", map.height);
// 	map.matrix = ft_store_map(ft_open_map(argv[1]), &map);
// 	while (map.matrix[i])
// 	{
// 		printf("%s", map.matrix[i]);
// 		free(map.matrix[i]);
// 		i++;
// 	}
// 	return (0);
// }

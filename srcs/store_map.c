/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:09:36 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/11 04:29:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				exit(EXIT_SUCCESS);
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

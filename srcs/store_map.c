/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:09:36 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/14 14:42:03 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parser(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 4] == '.' && path[len - 3] == 'b'
		&& path[len - 2] == 'e' && path[len - 1] == 'r')
		return (TRUE);
	return (FALSE);
}

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
	if (!ft_parser(path))
		ft_print_error(INVALID_EXT, "Map error: Not .ber file");
	return (open(path, O_RDONLY));
}

int	ft_get_map_size(int fd, t_map *map)
{
	char	*line;

	if (fd <= 0)
		ft_print_error(INVALID_FD, "Map error: Cannot open the file");
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
				ft_print_error(INVALID_MAP,
					"Map error: Not all the lines have the same length");
			free(line);
		}
	}
	close(fd);
	return (0);
}

char	**ft_store_map(int fd, t_map *map)
{
	int		i;

	map->matrix = (char **)malloc(sizeof(char *) * map->height + 1);
	if (!map->matrix)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = (char *)malloc(sizeof(char) * map->wide);
		if (!map->matrix[i])
			return (ft_free(map->matrix, i));
		map->matrix[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map->matrix);
}

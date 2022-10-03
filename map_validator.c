/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:41 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/03 21:01:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_lines(void)
{
	int		fd;
	char	*line;
	int		size_line;

	fd = open("./mapa", O_RDONLY);
	size_line = 0;
	line = get_next_line(fd);
	if (line)
		size_line = ft_line_lenght(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (size_line != ft_line_lenght(line))
			{
				printf("\nMap Invalid");
				return (-1);
			}
			free(line);
		}
	}
	printf("\nMap Valid");
	close(fd);
	return (size_line);
}

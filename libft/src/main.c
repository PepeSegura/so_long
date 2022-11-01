/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:34:27 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/31 20:53:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
//Open
#include <fcntl.h>

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	char	*line = "HOLA";

	ft_printf("%d", OPEN_MAX);
	atexit(ft_leaks);
	fd = open("./src/get_next_line.c", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			ft_printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

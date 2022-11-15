/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_selector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:41:42 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/15 17:50:00 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printf_selector(void)
{
	ft_printf("\033c");
	ft_printf("\033c\033[0;94mChoose a map:\n\n");
	ft_printf("\033[0;96m1 -> subject_small_map\n");
	ft_printf("\033[0;96m2 -> subject_big_map\n");
	ft_printf("\033[0;96m3 -> map_with_enemies\n");
	ft_printf("\033[0;96m4 -> psegura-\n");
	ft_printf("\033[0;94;5m\nWrite a number between 1-7 and press enter:\n\n");
}

char	*ft_map_selector(char *file)
{
	printf_selector();
	file = get_next_line(0);
	if (file[0] == '1' && file[1] == '\n')
	{
		free(file);
		return ("maps/valid_maps/subject_map_1.ber");
	}
	if (file[0] == '2' && file[1] == '\n')
	{
		free(file);
		return ("maps/valid_maps/subject_map_2.ber");
	}
	if (file[0] == '3' && file[1] == '\n')
	{
		free(file);
		return ("maps/valid_maps/subject_map_enemies.ber");
	}
	if (file[0] == '4' && file[1] == '\n')
	{
		free(file);
		return ("maps/valid_maps/pepe.ber");
	}
	free(file);
	ft_print_error(DIDNT_CHOOSED, "You didn't choose a valid number");
	return (NULL);
}

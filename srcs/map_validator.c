/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:41 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/13 06:52:28 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_top_bot_row(t_cosas *c)
{
	int	i;
	int	top;
	int	j;
	int	bot;

	i = 0;
	while (c->map.matrix[0][i] != '\n')
	{
		top = TRUE;
		if (c->map.matrix[0][i] != WALL_CHAR)
			return (FALSE);
		i++;
	}
	j = 0;
	while (c->map.matrix[c->map.height - 1][j] != '\n')
	{
		bot = TRUE;
		if (c->map.matrix[c->map.height - 1][j] != WALL_CHAR)
			return (FALSE);
		j++;
	}
	if (top == TRUE || bot == TRUE)
		return (TRUE);
	return (FALSE);
}

void	ft_check_mid_row(char *row, t_map *map)
{
	int	i;

	if (row[0] != WALL_CHAR || row[map->wide - 1] != WALL_CHAR)
		ft_print_error(NOT_CLOSED, "Map error: Map not closed");
	i = 0;
	while (i < map->wide)
	{
		if (!ft_strchr(VALID_CHARS, row[i]))
			ft_print_error(INVALID_CHAR, "Map error: Invalid char on the map");
		++i;
	}
}

void	ft_valid_map(t_cosas *c)
{
	if (c->map.wide == c->map.height)
		ft_print_error(SQUARE_MAP, "Map error: Map not rectangular");
	if (c->map.reqs.p_count != 1)
		ft_print_error(INVALID_P, "Map error: Invalid number of players");
	if (c->map.reqs.c_count < 1)
		ft_print_error(INVALID_C, "Map error: Not enough collectibles");
	if (c->map.reqs.e_count != 1)
		ft_print_error(INVALID_E, "Map error: Invalid number of exits");
	if (ft_top_bot_row(c) == FALSE)
		ft_print_error(NOT_CLOSED, "Map error: Map not closed");
}

void	ft_print_error(int error_code, char *error_message)
{
	if (error_code == DEAD)
		ft_printf("\033cBuggy killed you :(");
	else if (error_code == WIN)
		ft_printf("\033cYou found the one piece!");
	else
		ft_printf("Error\n\tError code: %d\n\t%s", error_code, error_message);
	exit(error_code);
}

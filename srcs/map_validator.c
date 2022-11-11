/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:41 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/11 04:16:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_lines(t_cosas *c)
{
	if (c->map.wide == c->map.height)
		ft_print_error(SQUARE_MAP, "Map error: Map not rectangular");
	if (c->map.reqs.p_count != 1)
		ft_print_error(INVALID_P, "Map error: Invalid number of players");
	if (c->map.reqs.c_count < 1)
		ft_print_error(INVALID_P, "Map error: Not enough collectibles");
	if (c->map.reqs.e_count != 1)
		ft_print_error(INVALID_P, "Map error: Invalid number of exits");
}

void	ft_print_error(int error_code, char *error_message)
{
	printf("Error code: %d\n%s", error_code, error_message);
	exit(error_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:11:20 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/10 02:30:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Constantes
# define TRUE 1
# define FALSE 0

//Errores
# define INVALID_MAP -1
# define SQUARE_MAP -10

//Map char
# define VALID_CHARS		"01CEP"
# define EMPTY_CHAR			'0'
# define WALL_CHAR			'1'
# define COLLECTIBLE_CHAR	'C'
# define EXIT_CHAR			'E'
# define PLAYER_CHAR		'P'

//XPM
# define XPM_SIZE	50
# define EMPTY_PATH			"./sprites/xpm/suelo50.xpm"
# define WALL_PATH			"./sprites/xpm/wall50v2.xpm"
# define COLLECTIBLE_PATH	"./sprites/xpm/up50.xpm"
# define EXIT_PATH			"./sprites/xpm/cofre50.xpm"
# define PLAYER_PATH		"./sprites/xpm/player50.xpm"

#endif

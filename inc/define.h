/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:11:20 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/01 15:12:44 by psegura-         ###   ########.fr       */
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

//Keys
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# define UP		126
# define LEFT	123
# define DOWN	125
# define RIGHT	124

//XPM
# define XPM_SIZE	50
# define EMPTY_PATH			"./sprites/others/suelo50.xpm"
# define WALL_PATH			"./sprites/others/wall50v2.xpm"
# define COLLECTIBLE_PATH	"./sprites/others/fruta50.xpm"
# define EXIT_PATH			"./sprites/others/cofre50.xpm"
# define PLAYER_PATH		"./sprites/player/luffy/luffy_xpm/luffy__right250.xpm"

#endif

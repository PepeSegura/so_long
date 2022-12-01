/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:11:20 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/29 15:02:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Constantes
# define TRUE 			1
# define FALSE 			0
# define TEXT_COLOR		0xff6e6e
# define NUMBER_COLOR	0xa4ffff

//Errores
# define INVALID_MAP	-1
# define INVALID_FD		-2
# define INVALID_EXT	-3
# define INVALID_CHAR	-4
# define SQUARE_MAP		-10
# define INVALID_P		-11
# define INVALID_SPRITE	-12
# define INVALID_C		-13
# define INVALID_E		-14
# define NOT_CLOSED		-15
# define INVALID_PATH	-16
# define DEAD			-17
# define WIN			-18
# define DIDNT_CHOOSED	-19

//Map char
# define VALID_CHARS		"01CEPB"
# define EMPTY_CHAR			'0'
# define WALL_CHAR			'1'
# define COLLECTIBLE_CHAR	'C'
# define EXIT_CHAR			'E'
# define PLAYER_CHAR		'P'
# define ENEMIE_CHAR		'B'

//Keys
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# define UP			126
# define LEFT		123
# define DOWN		125
# define RIGHT		124
# define DESTROY 	17

//XPM
# define XPM_SIZE	50
# define EMPTY_PATH			"./sprites/others/suelo50.xpm"
# define WALL_PATH			"./sprites/others/wall50v2.xpm"
# define COLLECTIBLE_PATH	"./sprites/others/fruta50.xpm"
# define EXIT_PATH			"./sprites/others/closed_door.xpm"
# define EXIT_OPEN_PATH		"./sprites/others/open_door.xpm"
# define ENEMIE_PATH		"./sprites/others/buggy50.xpm"
# define PLAYER_PATH		"./sprites/player/luffy_right2.xpm"

//Player
# define PLAYER_UP		"./sprites/player/luffy_up2.xpm"
# define PLAYER_LEFT	"./sprites/player/luffy_left2.xpm"
# define PLAYER_DOWN	"./sprites/player/luffy_down2.xpm"
# define PLAYER_RIGHT	"./sprites/player/luffy_right2.xpm"
#endif

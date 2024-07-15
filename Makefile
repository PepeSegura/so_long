# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2022/11/28 05:37:00 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =							\
		srcs/create_imgs.c		\
		srcs/draw.c				\
		srcs/init.c				\
		srcs/input.c			\
		srcs/main.c				\
		srcs/map_selector.c		\
		srcs/map_validator.c	\
		srcs/movement.c			\
		srcs/read_map.c			\
		srcs/store_map.c		\
		srcs/utils.c			\
		srcs/validate_path.c	\

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

FLAGS_MLX = -lXext -lX11 -lm -lz
MLX_LIB = minilibx-linux/libmlx.a

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(LIB) $(MLX_LIB) -o $(NAME)
	@echo "🏂 so_long Done 🏂"

all: $(NAME)

clean:
	make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

test:
	bash ./map_tester.sh
	
leaks:
	@echo 7768696c6520747275653b646f206c65616b7320736f5f6c6f6e673b20736c65657020323b20646f6e653b | xxd -r -p | zsh
	
.PHONY: all clean fclean re norma test leaks
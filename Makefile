# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2022/11/11 01:08:04 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =						\
		srcs/main.c			\
		srcs/draw.c			\
		srcs/utils.c		\
		srcs/input.c		\
		srcs/movement.c		\
		srcs/store_map.c	\
		srcs/read_map.c		\
		srcs/map_validator.c\

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(FLAGS_MLX) $(OBJS) $(LIB) -o $(NAME)
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
	
.PHONY: all clean fclean re norma
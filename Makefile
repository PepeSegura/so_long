# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2022/11/01 14:26:39 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/main.c\
		srcs/utils.c	\
		srcs/map_validator.c	\
		srcs/store_map.c	\
		srcs/input.c		\
		srcs/draw.c	\
		# movement.c	\

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(FLAGS_MLX) $(OBJS) $(LIB) -o $(NAME)
	@echo "🏂 so_long Done 🏂"

all: $(NAME)

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
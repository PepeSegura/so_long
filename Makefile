# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2022/11/07 18:42:22 by psegura-         ###   ########.fr        #
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

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2022/10/10 20:21:50 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
EXE = so_long

SRCS =	\
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		utils.c	\
		map_validator.c	\
		store_map.c	\
		movement.c	\
		input.c		\
		draw.c	\

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc
# FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

$(OBJS_DIR)%.o : %.c ./include/so_long.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "🏂 so_long Done 🏂"
	$(CC) $(FLAGS) $(FLAGS_MLX) main.c so_long.a -o $(EXE)

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(EXE)

re: fclean all

.PHONY: all clean fclean re hola
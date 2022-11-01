# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 20:21:59 by psegura-          #+#    #+#              #
#    Updated: 2022/10/30 22:58:45 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###

RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m

### Compiler info###

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I ./$(INCDIR)

### Source Files ###

SRCS_NAME = 						\
			ft_toupper.c			\
			ft_tolower.c			\
									\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
									\
			ft_strlen.c				\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strncmp.c			\
			ft_strnstr.c			\
			ft_strjoin.c			\
			ft_strmapi.c			\
			ft_striteri.c			\
			ft_strdup.c				\
									\
			ft_memset.c				\
			ft_memcpy.c				\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
									\
			ft_bzero.c				\
			ft_calloc.c				\
									\
			ft_substr.c				\
			ft_strtrim.c			\
			ft_split.c				\
									\
			ft_atoi.c				\
			ft_itoa.c				\
									\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
									\
		 	ft_lstnew.c				\
			ft_lstadd_front.c		\
			ft_lstsize.c			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstdelone.c			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
									\
			get_next_line.c			\
			get_next_line_utils.c	\
									\
			ft_printf.c				\
			ft_putnbr_base.c		\
			ft_printf_utils.c		\

### Files ###

SRCDIR = src
OBJDIR = obj
INCDIR = inc

### NAME ###

NAME = libft.a

### Rules ###

all: reset $(NAME)

### Clear Console ###

reset:
	@echo "$(RESET)"

### Create Objects ###

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NAME))
OBJS_NAME = $(SRCS_NAME:%.c=%.o)
OBJS = $(addprefix $(OBJDIR)/,$(OBJS_NAME))

### Objects dir ###

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
		@echo "$(GREEN)Compiling:$(RED) $<"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
		@mkdir -p $(OBJDIR) 2> /dev/null

### Compile Objects ###

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(CYAN)Libft Done!"

clean: reset
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)Objects Removed!"


fclean: reset clean
	@rm -rf $(NAME)
	@echo "$(CYAN)Libft.a Removed!"

re: fclean all

.PHONY: all clean fclean re reset

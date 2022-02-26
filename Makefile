# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmaziane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 04:48:59 by zmaziane          #+#    #+#              #
#    Updated: 2022/02/25 00:57:36 by zmaziane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = window.c \
	  so_long.c \
	  check_so.c \
	  play.c \
	  gnl/get_next_line_utils.c \
	  gnl/get_next_line.c \
	  ft_printf/ft_printf.c \
	  ft_printf/ft_putchar.c \
	  ft_printf/ft_puthex.c \
	  ft_printf/ft_putnbr.c \
	  ft_printf/ft_putstr.c \
	  ft_printf/ft_putunb.c \

OBJ = ${SRC:.c=.o}
CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX)  -o $(NAME)

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re : fclean all

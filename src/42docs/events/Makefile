# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:01:17 by pvaladar          #+#    #+#              #
#    Updated: 2022/07/28 16:01:39 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := events
SRC := events.c
#OBJ := fractol.o colours_1.o colours_2.o
CC := cc

MLX := ./mlx/libmlx.a

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(SRC)
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(CC) $(SRC) $(MLX) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -ggdb3 -o $(NAME)

fclean:
	rm -rf *.o $(NAME)

run: fclean $(NAME)
	./$(NAME)
	
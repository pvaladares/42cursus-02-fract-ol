# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:01:17 by pvaladar          #+#    #+#              #
#    Updated: 2022/08/04 14:40:48 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := cc

CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address,undefined,leak -O3

SRC :=	*.c

OBJ :=	${SRC:.c=.o}

#MLX := /usr/local/lib/libmlx.a
MLX := minilibx-linux/libmlx.a

$(NAME): $(SRC)
#	$(CC) $(CFLAGS) $(SRC) $(MLX) -lXext -lX11 -lm -lz -I/usr/local/include -g -ggdb3 -o $(NAME)
	$(CC) $(CFLAGS) $(SRC) $(MLX) -lXext -lX11 -lm -lz -g -ggdb3 -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run: fclean $(NAME)
	./$(NAME) 1 1

norm: $(SRC)
	norminette $(SRC) fractol.h

mlx:
	@echo "##### Installing MLX library locally! #####"
	@echo "==== Downling sources ===="
	@git clone https://github.com/42Paris/minilibx-linux
	@echo "==== Building MLX ===="
	@make -C minilibx-linux
#	@mv minilibx-linux libmlx
#	@echo "==== Copying the MLX library and manpages to local path ===="
#	@sudo cp minilibx-linux/*.a /usr/local/lib
#	@sudo cp minilibx-linux/*.h /usr/local/include
#	@sudo cp minilibx-linux/man/man1/mlx_pixel_put.1 minilibx-linux/man/man3/mlx_pixel_put.3
#	@sudo mkdir -p /usr/local/man/man3
#	@sudo cp minilibx-linux/man/man3/* /usr/local/man/man3
#	@echo "==== Removing the temporary folder ===="
#	@rm -rf minilibx-linux


.PHONY: all clean fclean re run norm mlx
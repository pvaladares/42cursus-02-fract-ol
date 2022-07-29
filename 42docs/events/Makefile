# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:01:17 by pvaladar          #+#    #+#              #
#    Updated: 2022/07/29 23:31:57 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := events

CC := cc

CFLAGS := -Wall -Werror -Wextra

SRC :=	events.c \
		hooks_config.c \
		hooks_keys_buttons.c \
		hooks_window.c \

OBJ :=	${SRC:.c=.o}

MLX := /usr/local/lib/libmlx.a

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(MLX) -lXext -lX11 -lm -lz -I/usr/local/include -g -ggdb3 -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run: fclean $(NAME)
	./$(NAME)

norm: $(SRC)
	norminette $(SRC) events.h

mlx:
	@echo "##### Installing MLX library locally! #####"
	@echo "==== Downling sources ===="
	@wget https://github.com/pvaladares/42cursus-02-fract-ol/raw/main/files/minilibx-linux.tgz
	@echo "==== Extracting ===="
	@tar -xf minilibx-linux.tgz
	@echo "==== Deleting compressed file (not required anymore) ===="
	@rm -rf minilibx-linux.tgz
	@echo "==== Building MLX ===="
	@make -C minilibx-linux
	@echo "==== Copying the MLX library and manpages to local path ===="
	@sudo cp minilibx-linux/*.a /usr/local/lib
	@sudo cp minilibx-linux/*.h /usr/local/include
	@sudo cp minilibx-linux/man/man1/mlx_pixel_put.1 minilibx-linux/man/man3/mlx_pixel_put.3
	@sudo mkdir -p /usr/local/man/man3
	@sudo cp minilibx-linux/man/man3/* /usr/local/man/man3
	@echo "==== Removing the temporary folder ===="
	@rm -rf minilibx-linux


.PHONY: all clean fclean re run norm mlx
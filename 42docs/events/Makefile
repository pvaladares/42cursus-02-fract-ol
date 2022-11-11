# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:01:17 by pvaladar          #+#    #+#              #
#    Updated: 2022/11/11 15:35:33 by pvaladar         ###   ########.fr        #
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

MLX_PATH := minilibx-linux
MLX := $(MLX_PATH)/libmlx.a

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
	@git clone https://github.com/42Paris/minilibx-linux
	@echo "==== Building MLX ===="
	@make -C $(MLX_PATH)

.PHONY: all clean fclean re run norm mlx
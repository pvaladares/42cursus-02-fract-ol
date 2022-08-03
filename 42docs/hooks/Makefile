# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:01:17 by pvaladar          #+#    #+#              #
#    Updated: 2022/08/03 12:30:36 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := hooks

CC := cc

CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address,undefined,leak

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
	./$(NAME)

norm: $(SRC)
	norminette $(SRC) hooks.h

mlx:
	@echo "##### Installing MLX library locally! #####"
	@echo "==== Downling sources ===="
	@git clone https://github.com/42Paris/minilibx-linux
	@echo "==== Building MLX ===="
	@make -C minilibx-linux


.PHONY: all clean fclean re run norm mlx
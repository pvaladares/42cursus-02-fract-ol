# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:01:17 by pvaladar          #+#    #+#              #
#    Updated: 2022/07/29 11:40:19 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := hooks

CC := cc

CFLAGS := -Wall -Werror -Wextra

SRC := hooks.c \
		hooks_config.c \
		hooks_keys_buttons.c \
		hooks_window.c

OBJS :=	${SRCS:.c=.o}

MLX := ./mlx/libmlx.a

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(MLX) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -ggdb3 -o $(NAME)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run: fclean $(NAME)
	./$(NAME)

norm: $(SRC)
	norminette $(SRC) hooks.h

.PHONY: all clean fclean re run norm
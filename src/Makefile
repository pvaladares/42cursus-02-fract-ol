NAME := fractol
SRC := fractol.c colours_1.c colours_2.c custom_mlx.c
#OBJ := fractol.o colours_1.o colours_2.o
CC := cc

MLX := ./mlx/libmlx.a

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(SRC)
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(CC) $(SRC) $(MLX) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -ggdb3 -o $(NAME)

fclean:
	rm -rf *.o fractol

run: fclean $(NAME)
	./$(NAME) 1 1
	
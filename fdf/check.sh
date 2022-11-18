#!/bin/sh

rm libft.a libmlx.a gnl.a

make -C./libs/libft
make -C./libs/MLX42
make -C./libs/get_next_line
NAME="a.out"
cp libs/libft/libft.a libft.a
cp libs/MLX42/libmlx42.a libmlx42.a
cp libs/get_next_line/gnl.a libgnl.a
SOURCES="functions.c fdf.h libs/MLX42/include/MLX42/MLX42.h main.c libs/get_next_line/get_next_line.h libs/libft/libft.h"
#gcc -I /usr/local/include $SOURCES main.c -L . -lft -lgnl -lmlx42 -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib -framework OpenGL -framework AppKit

gcc $SOURCES libmlx42.a libgnl.a libft.a -I include -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/"

./a.out
 rm a.out

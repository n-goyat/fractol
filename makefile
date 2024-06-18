# Makefile for fractol project (Linux)

# Name of the executable
NAME = fractol

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g
LDFLAGS = -Llibft -lft -L/MLX42 -lmlx42 -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Directories and libraries
MLX_PATH = ./MLX42/build/
MLX = $(MLX_PATH)/libmlx42.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Compiler
CC = gcc

# Source files
SRC = src/main.c src/error.c src/init.c src/math.c src/render.c
OBJ = $(SRC:%.c=%.o)

# Includes and libraries
INCLUDES = -I./includes -I./MLX42/include/MLX42/ -I./libft/
LIBS = -lglfw -lGL -lm -lX11 -lXrandr -lXi -lXxf86vm -lpthread -ldl

# Default target
all: MLX42 $(NAME)

# Build the executable
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) $(LIBS) -o $(NAME)

# Build MLX42 library
MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

# Compile source files
%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft library
$(LIBFT):
	make -C $(LIBFT_PATH)

# Clean up objects and executable
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@if [ -d "MLX42" ]; then rm -rf MLX42; fi

re: fclean all

.PHONY: all clean fclean re MLX42

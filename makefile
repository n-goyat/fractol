# Makefile for fractol project (Linux)

# Name of the executable
NAME = fractol

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

# Directories and libraries
MLX_PATH = ./MLX42/build
MLX = $(MLX_PATH)/libmlx42.a
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Compiler
CC = gcc

# Source files
SRC = fractol.c error.c init.c
OBJ = $(SRC:%.c=%.o)

# Includes and libraries
INCLUDES = -I./MLX42/include/MLX42/ -I./libft/ -I./includes/
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
%.o : src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft library
$(LIBFT):
	make -C $(LIBFT_PATH)

# Clean up objects and executable
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@if [ -d "MLX42" ]; then rm -rf MLX42; fi

re: fclean all

.PHONY: all clean fclean re MLX42
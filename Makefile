NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3	
MLX =  -lmlx -lm -framework OpenGL -framework AppKit
SRC = $(wildcard  *.c)
MATH = -lm
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<

$(NAME): $(OBJ)
	@$(MAKE) -C ./mlx -s
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ) $(MATH)

clean:
	@$(MAKE) clean -C ./mlx -s
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

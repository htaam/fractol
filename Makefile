NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX =  -lmlx -lm -framework OpenGL -framework AppKit
SRC = $(wildcard  *.c)
MATH = -lm
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ) $(MATH)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

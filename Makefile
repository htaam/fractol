NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3	

MLX =  -lmlx -lm -framework OpenGL -framework AppKit

SRC = atoi_with_error.c \
		atol.c \
		aux1.c \
		hook.c \
		input.c \
		julia.c \
		main.c \
		mandelbrot.c \
		zoom.c
SRCSFD = srcs/
OBJSFD = objs/
MATH = -lm
OBJS = $(addprefix $(OBJSFD),$(SRC:.c=.o))

HDRSFD = includes/

HDR = fractol.h

HDRS = $(addprefix $(HDRSFD),$(HDR))

HDR_INC = -I./includes

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m


all: $(NAME)

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] objs/ directory"

$(OBJSFD)%.o: $(SRCSFD)%.c $(HDRS)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

$(NAME): project $(OBJSFD) $(OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(MLX) $(OBJS) $(LIB_BINARY) -o $@
	@$(MAKE) -C ./mlx -s 
	@echo "\t[ \033[0;32m✔\033[0m ] fractol executable"

project:
	@echo "Checking project..."

clean:
	@rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"

re: fclean all

.PHONY: all project clean fclean re
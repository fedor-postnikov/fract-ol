NAME = fractol

SYS_LIB_DIR = /usr/X11/lib
SYS_INC_DIR = /usr/X11/include

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx.a

HEADERS = $(LIBFT_DIR)/libft.h $(MLX_DIR)/mlx.h

SRC = \
	fractol.c \
	usage.c \
	fractals.c \
	utils.c \
	draw.c \
	events.c \
	move_mouse.c \
	move_keyboard.c \
	parse.c \
	colors.c \

OBJS = $(SRC:.c=.o)
INCS = -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SYS_INC_DIR)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
CFLAGS_DEBUG = -Wall -Wextra -Werror -g -fsanitize=address

# LFLAGS depends on system you use: MacOS or Linux
SHELL:=/bin/bash
UNAME_S = $(shell uname -s)
ifneq ($(UNAME_S), Linux)
	LFLAGS = -L $(LIBFT_DIR) -L $(MLX_DIR) -L $(SYS_LIB_DIR) \
		-lft \
		-lmlx -lm -lXext -lX11 \
		-framework OpenGL -framework AppKit
else
	LFLAGS = -L $(LIBFT_DIR) -L $(MLX_DIR) -L $(SYS_LIB_DIR) \
		-lft \
		-lmlx -lm -lXext -lX11
endif

%.o :	%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C mlx

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug:
	@make re CFLAGS="$(CFLAGS_DEBUG)"

norm:
	norminette $(SRC) $(HEADERS)

.PHONY:		all clean fclean re debug norm

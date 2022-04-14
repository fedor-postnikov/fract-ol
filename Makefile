NAME = fractol

LIBFT_DIR = ./libft/
LIBFT = ${LIBFT_DIR}libft.a

HEADERS = ${LIBFT_DIR}/libft.h fractol.h

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

OBJS = ${SRC:.c=.o}
INCS = -I${LIBFT_DIR}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
CFLAGS_DEBUG = -Wall -Wextra -Werror -g -fsanitize=address
LFLAGS = -L ${LIBFT_DIR} \
	-lmlx \
	-lft \
	-framework OpenGL -framework AppKit

%.o :	%.c ${HEADERS}
	${CC} ${CFLAGS} ${INCS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCS} ${OBJS} ${LFLAGS} -o ${NAME}

${LIBFT}:
	@make -C libft

clean:
	${RM} ${OBJS}
	@make clean -C libft

fclean:	clean
	${RM} ${NAME}
	@make fclean -C libft

re:	fclean all

debug:
	@make re CFLAGS="${CFLAGS_DEBUG}"

norm:
	norminette ${SRC} ${HEADERS}

.PHONY:		all clean fclean re debug norm

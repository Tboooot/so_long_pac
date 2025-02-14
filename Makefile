
.PHONY	= all bonus clean fclean re

NAME		= so_long
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
HEADER		= so_long.h


LIBFT	= libft.a
MLX		= mlx.a
IFT		= -Ilibft -Llibft -lft
IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11

SRCS	= \
	main.c \
	map.c \
	validate_sides.c \
	validate_attributes.c \
	init.c \
	events.c \
	render.c \
	controls.c \
	movement.c \
	ft_alt_gnl.c \
	cleanup.c


OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${IFT} ${IMLX} -o $@



${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${LIBFT} ${MLX}


${OBJSDIR}/%.o: src/%.c src/so_long.h Makefile
	${CC} ${CFLAGS} -c $< -o $@



${LIBFT}: | libft
	${MAKE} -C libft/

${MLX}: | mlx
	${MAKE} -C mlx/



mlx:
	git clone https://github.com/42Paris/minilibx-linux.git mlx

clean:
	${MAKE} clean -C libft
	${MAKE} clean -C mlx
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf libft mlx ${NAME} 

re: fclean all

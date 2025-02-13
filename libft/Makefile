
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 17:12:17 by frosa-ma          #+#    #+#              #
#    Updated: 2022/08/21 21:53:43 by frosa-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all clean fclean re bonus

NAME	= libft.a
CC		= clang
INC		= -Ift_printf
CFLAGS	= -Wall -Wextra -Werror

PRINTF_SRCS	= \
	ft_printf.c \
	ft_printf_utils.c \
	dot_disp.c \
	dot_wr.c \
	dot.c \
	minus_disp.c \
	minus_wr.c \
	minus.c \
	space_disp.c \
	space_wr.c \
	space.c \
	zero_disp.c \
	zero_wr.c \
	zero.c \
	sharp.c \
	plus.c \

SRCS	= \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_atoll.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_putnbr_hex.c \
	ft_ultoa.c \
	ft_utoab.c \
	ft_utoa.c \
	ft_putptr.c \
	ft_putnstr.c \
	ft_strjoins.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstpop.c \
	ft_lstdel.c \
	ft_free_matrix.c \
	ft_gnl.c \
	ft_dlstadd_back.c \
	ft_dlstadd_front.c \
	ft_dlstlast.c \
	ft_dlsthead.c \
	ft_dlstnew.c

OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${NAME}: ${OBJSDIR} ${OBJS}
	ar -rcs $@ $</*.o
	${MAKE} -C ft_printf/
	ar -rs $@ ft_printf/obj/*.o
	rm -rf ft_printf/libftprintf.a

${OBJSDIR}:
	mkdir -p $@

${OBJSDIR}/%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: all

clean:
	${MAKE} fclean -C ft_printf
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all


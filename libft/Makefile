# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtarza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:59:15 by mtarza            #+#    #+#              #
#    Updated: 2024/11/06 18:04:59 by mtarza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c get_next_line.c  get_next_line_utils.c
HEAD		= libft.h



FT_PRINTF_SRC = 	  ft_pointer.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hexa_lower.c ft_putnbr_hexa_upper.c ft_putnbr_unsigned.c ft_putstr.c ft_strlen_o.c

INC =		-I. -Ift_printf
FT_PRINTF_DIR = ft_printf

FT_PRINTF_NAME = libftprintf.a
NAME		= libft.a

CC			= cc
RM			= rm -f
AR			= ar rcs

CFLAGS			= -Wall -Wextra -Werror 

OBJ = $(SRCS:.c=.o)
PRINTF_OBJ = $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC:.c=.o))



all:		$(NAME) $(FT_PRINTF_NAME)

$(NAME):	${OBJ}
			${AR} ${NAME} ${OBJ}

$(FT_PRINTF_NAME) : ${PRINTF_OBJ}
			${AR} ${FT_PRINTF_NAME} ${PRINTF_OBJ}

%.o: %.c
		${CC} ${CFLAGS} ${INC} -c $< -o $@
	
$(FT_PRINTF_DIR)/%.o : $(FT_PRINTF_DIR)/%.c 
			${CC} ${CFLAGS} ${INC} -c $< -o $@

clean:
			${RM} ${OBJ} ${PRINTF_OBJ}

fclean:		clean
	${RM} $(NAME) ${FT_PRINTF_NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re

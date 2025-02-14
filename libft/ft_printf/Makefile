# **************************************************************************** # #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtarza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 07:17:30 by mtarza            #+#    #+#              #
#    Updated: 2024/12/19 07:17:36 by mtarza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_pointer.c	ft_printf.c	ft_putchar.c	ft_putnbr.c \
	ft_putnbr_hexa_lower.c	ft_putnbr_hexa_upper.c	ft_putnbr_unsigned.c \
	ft_putstr.c	ft_strlen_o.c	
	
OBJECT = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECT)
	$(AR) $(NAME) $(OBJECT)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

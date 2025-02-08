
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Tboooot <tboooot@student.42.fr>            +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025-02-05 18:13:48 by Tboooot           #+#    #+#             #
#    Updated: 2025-02-05 18:13:48 by Tboooot          ###   ########.fr       #
#                                                                              #
# **************************************************************************** #
NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./includes -g

# Sources
SRC_DIR		= src
SRCS		= main.c \
			  $(SRC_DIR)/map/map_parsing.c \
			  $(SRC_DIR)/map/map_utils.c\
			  $(SRC_DIR)/map/map_characters.c \
			  $(SRC_DIR)/map/map_validation.c \
			  $(SRC_DIR)/libft/ft_calloc.c \
			  $(SRC_DIR)/libft/ft_putendl_fd.c \
			  $(SRC_DIR)/libft/ft_putstr_fd.c \
			  $(SRC_DIR)/libft/ft_split.c \
			  $(SRC_DIR)/libft/ft_strncmp.c \
			  $(SRC_DIR)/libft/ft_strdup.c \
			  $(SRC_DIR)/libft/ft_strjoin.c \
			  $(SRC_DIR)/libft/ft_strlen.c \
			  $(SRC_DIR)/gnl/get_next_line.c \
			  $(SRC_DIR)/gnl/get_next_line_utils.c

# Objects
OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Compilation progress
$(OBJS): | compile_start

compile_start:
	@echo "$(YELLOW)Starting compilation...$(RESET)"

# Error handling
%.c:
	@echo "$(RED)Error: Source file $@ not found!$(RESET)"
	@exit 1

# Additional targets for testing
test: $(NAME)
	@echo "$(YELLOW)Running basic tests...$(RESET)"
	@./$(NAME) maps/valid.ber || true
	@./$(NAME) maps/invalid.ber || true
	@./$(NAME) || true

# Help target
help:
	@echo "$(GREEN)Available targets:$(RESET)"
	@echo "  make        - Compile the project"
	@echo "  make clean  - Remove object files"
	@echo "  make fclean - Remove object files and executable"
	@echo "  make re     - Recompile the project"
	@echo "  make test   - Run basic tests"
	@echo "  make help   - Show this help message"


# Project Name
NAME		= so_long

# Compiler and Flags
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
MLX_DIR		= mlx

# Source Files
SRCS		= main.c \
			  map.c \
			  validate_sides.c \
			  validate_attributes.c \
			  init.c \
			  events.c \
			  render.c \
			  controls.c \
			  movement.c \
			  cleanup.c

# Object Files
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFTPRINTF	= $(LIBFT_DIR)/ft_printf/libftprintf.a
MLX			= $(MLX_DIR)/libmlx.a

# Include and Library Flags
INCLUDES	= -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf \
			  -L$(MLX_DIR) -lmlx -lXext -lX11

# Color codes
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m # No Color

# Main Rules
all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(LIBFTPRINTF) $(MLX) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) successfully compiled!$(NC)"

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile libraries
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	@echo "$(YELLOW)Building ft_printf...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)/ft_printf

$(MLX):
	@echo "$(YELLOW)Building MLX...$(NC)"
	@$(MAKE) -C $(MLX_DIR)

# Clean rules
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR)/ft_printf clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning everything...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR)/ft_printf fclean
	@rm -f $(MLX)

re: fclean all

# Clone MLX if not exists
mlx:
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

.PHONY: all clean fclean re mlx

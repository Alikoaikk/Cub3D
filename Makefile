# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 01:38:57 by akoaik            #+#    #+#              #
#    Updated: 2026/01/28 15:55:29 by akoaik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
RED    = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
BLUE   = \033[0;34m
CYAN   = \033[0;36m
BOLD   = \033[1m
RESET  = \033[0m

OK     = $(GREEN)$(BOLD)✓$(RESET)

SRC_DIR = src
PARSE_DIR = $(SRC_DIR)/parsing
RENDER_DIR = $(SRC_DIR)/rendering
MOVE_DIR = $(SRC_DIR)/movements

LIBFT_DIR = libft
MLX_DIR = minilibx

SRC = main.c \
	$(PARSE_DIR)/colors_parsing.c \
	$(PARSE_DIR)/colors_extraction.c \
	$(PARSE_DIR)/get_next_line.c \
	$(PARSE_DIR)/get_next_line_utils.c \
	$(PARSE_DIR)/map_parsing.c \
	$(PARSE_DIR)/map_dimensions.c \
	$(PARSE_DIR)/map_parsing_helpers.c \
	$(PARSE_DIR)/map_parsing_utils.c \
	$(PARSE_DIR)/map_parsing_utils2.c \
	$(PARSE_DIR)/parsing_utils.c \
	$(PARSE_DIR)/textures_parsing.c \
	$(PARSE_DIR)/textures_parsing_helpers.c \
	$(PARSE_DIR)/textures_parsing_utils.c \
	$(PARSE_DIR)/validation_utils.c \
	$(PARSE_DIR)/check_row.c \
	$(RENDER_DIR)/camera_plane.c \
	$(RENDER_DIR)/dda.c \
	$(RENDER_DIR)/dda_setup.c \
	$(RENDER_DIR)/drawing.c \
	$(RENDER_DIR)/raycasting.c \
	$(RENDER_DIR)/textures_images.c \
	$(MOVE_DIR)/control_movements.c \
	$(MOVE_DIR)/cleanup.c \
	$(MOVE_DIR)/player_movements.c \
	$(MOVE_DIR)/player_rotations.c


OBJ = $(SRC:.c=.o)

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBS = -L$(LIBFT_DIR) -lft \
	   -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CYAN)$(BOLD)Building libraries...$(RESET)\n"
	@make -C $(LIBFT_DIR) --no-print-directory -s
	@printf "  $(OK) $(YELLOW)libft$(RESET)\n"
	@make -C $(MLX_DIR) --no-print-directory -s 2>/dev/null
	@printf "  $(OK) $(YELLOW)minilibx$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "$(GREEN)$(BOLD)\n  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗\n$(RESET)"
	@printf "$(GREEN)$(BOLD) ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n$(RESET)"
	@printf "$(GREEN)$(BOLD) ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n$(RESET)"
	@printf "$(GREEN)$(BOLD) ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n$(RESET)"
	@printf "$(GREEN)$(BOLD) ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n$(RESET)"
	@printf "$(GREEN)$(BOLD)  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝\n\n$(RESET)"
	@printf "$(OK) $(BOLD)$(NAME) compiled successfully!$(RESET)\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "  $(OK) $(BLUE)%-45s$(RESET)\n" $<

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean --no-print-directory -s
	@make -C $(MLX_DIR) clean --no-print-directory -s 2>/dev/null
	@printf "$(RED)$(BOLD)  [clean]$(RESET) object files removed\n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory -s
	@printf "$(RED)$(BOLD)  [fclean]$(RESET) $(NAME) removed\n"

re: fclean all

.PHONY: all clean fclean re

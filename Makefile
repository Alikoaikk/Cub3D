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
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

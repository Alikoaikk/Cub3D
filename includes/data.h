/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:58:40 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 18:05:46 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <X11/X.h>      // for keys press and release
# include <X11/keysym.h> // for keys press and release
# include <fcntl.h>      // for open a file
# include <math.h>
# include <stdio.h>  //for printf
# include <stdlib.h> //for malloc , free, size_t , NULL , etc..
# include <unistd.h> //for read,write, ssize_t functions
# include "libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define MOVESPEED 0.03
# define ROTSPEED 0.015

// GET NEXT LINE

typedef struct s_block
{
	char				c;
	struct s_block		*next;
}						t_block;

typedef struct s_fdblock
{
	int					fd;
	t_block				*head;
	struct s_fdblock	*next;
}						t_fdblock;

char					*get_next_line(int fd);
char					*alloc_string(t_block **head);
int						find_new_line(t_block *head);
void					add_back(char c, t_block **head);
int						check_read(ssize_t bytes_read, t_block **head);
int						length(t_block *head);
void					free_head(t_block **head);
int						create_head(t_block **head, int fd, char *buffer,
							t_fdblock *current_fd);
t_fdblock				*find_current_fd(t_fdblock **lst, int fd);

// CUB 3D

typedef struct s_map
{
	char				**map;
	char				**copy;
	char				**padded_map;
	int					max_width;
	int					height;
}						t_map;

typedef struct s_walls
{
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
}						t_walls;

typedef struct s_colors
{
	int					floor_color[3];
	int					ceiling_color[3];
	int					floor;
	int					ceiling;
}						t_colors;

typedef struct s_player
{
	char				orientation;
	double				x;
	double				y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}						t_player;

typedef struct s_checker
{
	int					we;
	int					ea;
	int					so;
	int					no;
	int					f;
	int					c;
}						t_checker;

typedef struct s_mlx
{
	void				*mlx;
	void				*game;
	void				*img;
	int					*addr;
	int					bpp;
	int					line_len;
	int					endian;
}						t_mlx;

typedef enum e_wall
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}						t_wall;

typedef struct s_texture
{
	void				*img;
	int					*addr;
	int					width;
	int					height;
	int					bpp;
	int					line_len;
	int					endian;
}						t_texture;

typedef struct s_textures
{
	t_texture			walls[4];
}						t_textures;

typedef struct s_ray
{
	double				camera_x;
	double				raydir_x;
	double				raydir_y;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	double				deltadist_x;
	double				deltadist_y;
	double				sidedist_x;
	double				sidedist_y;
	int					side;
	double				perpwall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	double				step;
	double				tex_pos;
	int					tex_x;
	int					tex_y;

}						t_ray;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
}						t_keys;

typedef struct s_data
{
	t_map				map;
	t_walls				textures;
	t_colors			colors;
	t_player			player;
	t_ray				ray;
	t_mlx				mlx;
	t_textures			walls;
	t_keys				keys;
	t_texture			wand;
	int					fd;
}						t_data;

// file validation
void					file_validation(char *file, t_data *data);

// parsing data
void					parsing_data(t_data *data, t_checker *checker,
							t_walls *walls, char *file);
void					init_checker(t_checker *checker);
int						check_row_walls_only(char *row);
int						check_row_edges(char *row);

// parsing textures

void					parse_textures(t_data *data, t_checker *checker,
							t_walls *walls, char **stash);
char					*fill_buffer(t_data *data);
char					*extract_line(char **stash, char *buffer);
char					*allocate_line(int size, char **stash);
int						is_empty_line(char *line);
int						validate_line(char *line, t_checker *checker,
							t_walls *walls);
int						check_appearance(t_checker *checker, char *line);
int						validate_texture_path(t_walls *walls, char *line);
int						path_exist(t_walls *walls, char *line, char *temp);
void					init_walls(t_walls *walls, char *line, char *path);

// parsing colors
void					parse_colors(char **stash, t_data *data,
							t_checker *checker);
int						check_line(char *line);
int						validate_colors(char *line, t_colors *colors,
							int *count, t_checker *checker);
int						extract_and_fill(char *line, int colors[3]);
int						validate_characters(char *s);
int						check_count(int count);

// map parsing
void					parsing_map(t_data *data, char *file);
char					**read_map(t_data *data, char *file);
int						is_map_line(char *line);
int						valid_characters(char **map);
int						is_valid_character(char c);
void					validate_player(t_data *data);
void					path_validation(t_data *data);
int						validate_map_boundaries(t_map *map);
char					**duplicate_map(t_map *map);
int						flood_fill(t_data *data);
void					dfs(int *leak, t_data *data, int x, int y);
void					process_line(char *line, int *max_width, t_map *map);
void					fill_map(t_data *data, char *file);
int						get_map_dimensions(t_data *data, char *file,
							int *max_width);
void					map_padding(t_map *map);
char					*create_padded_line(char *line, int max_width);

// rendering
void					rendering(t_data *data);
void					init_camera(t_player *player);
void					init_camera_north_direction(t_player *player);
void					init_camera_south_direction(t_player *player);
void					init_camera_east_direction(t_player *player);
void					init_camera_west_direction(t_player *player);
void					raycasting(t_data *data);
void					compute_ray_direction(t_data *data, int column);
void					setup_dda(t_data *data);
void					setup_distances_along_ray(t_ray *ray);
void					setup_side_distances(t_ray *ray, t_player *player);
void					perform_dda(t_ray *ray, char **padded_map);
void					calculate_line_height(t_data *data);
void					calculate_wall_hit_position(t_data *data);
t_texture				*select_wall_texture(t_data *data);
void					draw_wall_slice(t_data *data, int x, t_texture *tex);
void					put_pixel_to_screen(t_mlx *mlx, int x, int y,
							int color);
int						update_frame(t_data *data);
void					choose_colors(t_data *data);
int						load_textures(t_textures *textures, t_mlx *mlx,
							t_walls *walls);
int						load_north_texture(t_texture *walls, void *mlx,
							char *path);
int						load_south_texture(t_texture *walls, void *mlx,
							char *path);
int						load_west_texture(t_texture *walls, void *mlx,
							char *path);
int						load_east_texture(t_texture *walls, void *mlx,
							char *path);
void					fill_floor_and_ceiling(t_data *data);
int						exit_game(t_data *data);
void					free_map(char **map);
void					free_textures(t_textures *textures, void *mlx);
int						load_wand(t_texture *wand, void *mlx);
void					draw_wand(t_data *data);
// movements

int						stop(int keycode, t_data *data);
int						move(int keycode, t_data *data);
void					move_forward(t_data *data);
void					move_backward(t_data *data);
void					move_right(t_data *data);
void					move_left(t_data *data);
void					rotate_right(t_data *data);
void					rotate_left(t_data *data);

// utils
void					free_split(char **s);
void					free_wall_paths(t_walls *walls);
void					colors_cleanup(char *line, char **stash, t_data *data);
#endif
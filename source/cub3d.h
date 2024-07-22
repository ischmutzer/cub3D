/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:29:39 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/22 15:44:09 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include "mlx.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>

# define PLAYER_SIZE 3
# define CELL_SIZE 7
# define VIEWPORT_SIZE_X 20
# define VIEWPORT_SIZE_Y 20
# define WALL_COLOR 0xFFFFFF
# define EMPTY_SPACE_COLOR 0x000000
# define BORDER_COLOR 0x808080
# define WALL_COLOR 0xFFFFFF
# define WIDTH   800
# define HEIGHT 600
# define PLY_S  0.01
# define ROT_S 0.008
# define IMG_SIZE 64

typedef struct s_vectors
{
	float	x;
	float	y;
	float	dir_x;
	float	dir_y;
	float	plan_x;
	float	plan_y;
	float	a;
	float	speed;
	float	rot_speed;
}	t_vectors;

typedef struct s_math
{
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	big_nb;
	float	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_math;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		esc;
	int		mouse_left;
	int		mouse_right;
}	t_keys;

typedef struct s_render
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_render;

typedef struct s_texture
{
	int		width;
	int		height;
	void	*ptr;
}	t_texture;

typedef struct s_map
{
	char	player;
	char	*floor_color;
	char	*ceiling_color;	
	char	**cells;
	char	*south;
	char	*north;
	char	*east;
	char	*west;
	char	**file;
	int		x;
	int		y;
	int		*floor;
	int		*ceiling;	
	int		map;
	int		y_axis;
	size_t	x_axis;
}	t_map;

typedef struct s_game
{
	t_keys		key;
	t_map		*map;
	t_render	img;
	t_texture	no_wall;
	t_texture	so_wall;
	t_texture	we_wall;
	t_texture	ea_wall;
	t_math		math;
	t_vectors	player;
	void		*mlx;
	void		*win;
	char		*img_data;
	char		**mini_map;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			tex_width;
	float		step;
	float		start_x;
	float		frame_time;
	float		start_y;
	float		end_x;
	float		end_y;
}	t_game;

//raycasting functions
void	load_tex(t_game *game, t_math *math);
void	initialize_raycasting(t_math *math, t_vectors *player, int x);
void	calculate_ray_direction(t_math *math);
void	initialize_step_and_side_dist(t_math *math, t_vectors *player);
void	perform_dda(t_math *math, t_map *map);

//init functions
void	init_game(t_game *game);

//freeing functions
void	free_map(t_map *map);
void	freeing_mlx_failed(t_game *game, char *str, int stage);
void	free_mini_map(t_game *game);
void	destroy_mlx_images(t_game *game);
void	free_array_revers(char **ret, int i);

//key check
void	check_north(t_game *game, int i);
void	check_south(t_game *game, int i);
void	check_east(t_game *game, int i);
void	check_west(t_game *game, int i);
void	check_floor(t_game *game, int i);
void	check_ceiling(t_game *game, int i);

//drawing functions
void	my_mlx_pixel_put(t_render *data, int x, int y, int color);
void	draw_map(t_game *game, t_map *map);
void	draw_ceiling_floor(t_game *game);

//handle keypress functions
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
void	w_pressed(t_game *game);
void	s_pressed(t_game *game );
void	d_pressed(t_game *game );
void	a_pressed(t_game *game );
void	left_pressed(t_game *game );
void	right_pressed(t_game *game );
void	d_update(t_vectors *player);
void	d_rotate_player(t_vectors *player);
void	a_update(t_vectors *player);
void	a_rotate_player(t_vectors *player);
int		handle_mouse(int x, int y, t_game *game);
int		close_game(t_game *game);
int		game_loop(t_game *game);
void	raycasting(t_game *game, t_vectors *player, t_map *map);

//PARSER

//check_map_borders_player.c
void	check_map(t_game *game, char **map);

//config_file_utils.c
void	print_error(char *str, int status, t_game *game);
void	is_trailing_space(t_game *game, char *str);
int		count_lines(char **config_file);
int		ft_strcmp(const char *s1, const char *s2);

//freeing_functions.c
void	free_directions_colors(t_game *game);
void	free_array(char **array);
void	free_game(t_game *game);

//free_extras.c
void	free_extras(t_game *game);

//map_validation_utils.c
void	convert_space_to_wall(t_game *game);
char	**read_file(t_game *game, int fd, char *read, char *full);
int		calculate_size(t_game *game, int index);
void	get_map_width(t_game *game, int index, int size);

//parsing.c
void	parser(t_game *game, char *file);

//store_map.c
void	store_map(t_game *game, int index);

//validate_CF.c
void	check_floor(t_game *game, int i);
void	check_ceiling(t_game *game, int i);

//validate_file_textures_colors.c
void	check_file(char *file, t_game *game);
void	check_textures(t_game *game);
void	check_colors(t_game *game, char *color, int flag);

//validate_map.c
void	validate_map2(t_game *game, char **map, int y, int x);
void	validate_map(t_game *game, char **map);

//validate_NSEW.c
void	check_north(t_game *game, int i);
void	check_south(t_game *game, int i);
void	check_east(t_game *game, int i);
void	check_west(t_game *game, int i);

//validate_up_down_right_left.c
int		validate_up(t_game *game, char **map, int y, int x);
int		validate_down(char **map, int y, int x);
int		validate_right(char **map, int x_axis, int y, int x);
int		validate_left(t_game *game, char **map, int y, int x);

//END PARSER

#endif
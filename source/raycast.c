/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:24:56 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/16 16:52:19 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_wall_dist(t_math *math)
{
	if (math->side == 0)
		math->perp_wall_dist = (math->side_dist_x - math->delta_dist_x);
	else
		math->perp_wall_dist = (math->side_dist_y - math->delta_dist_y);
}

static void	calculate_line_hight_draw_start_end(t_math *math)
{
	math->line_height = (int)(HEIGHT / math->perp_wall_dist);
	math->draw_start = -math->line_height / 2 + (float)HEIGHT / 2;
	if (math->draw_start < 0)
		math->draw_start = 0;
	math->draw_end = math->line_height / 2 + (float)HEIGHT / 2;
	if (math->draw_end >= HEIGHT)
		math->draw_end = HEIGHT - 1;
}

static void	calculate_wall_hit(t_math *math, t_vectors *player, t_game *game)
{
	double	wallx;

	if (math->side == 0)
		wallx = player->y + math->perp_wall_dist * math->ray_dir_y;
	else
		wallx = player->x + math->perp_wall_dist * math->ray_dir_x;
	wallx -= floor(wallx);
	game->tex_width = (int)(wallx * IMG_SIZE);
	if (math->side == 0 && math->ray_dir_x > 0)
		game->tex_width = IMG_SIZE - game->tex_width - 1;
	if (math->side == 1 && math->ray_dir_y < 0)
		game->tex_width = IMG_SIZE - game->tex_width - 1;
}

static void	draw_wall(t_game *game, t_math *math, int x)
{
	int		texture_height;
	float	texture_pos;
	int		y;
	int		texture_y;
	int		color;

	texture_height = game->size_line / (game->bits_per_pixel / 8);
	game->step = 1.0 * texture_height / math->line_height;
	texture_pos = (math->draw_start - HEIGHT
			/ 2 + math->line_height / 2) * game->step;
	y = math->draw_start;
	while (y < math->draw_end)
	{
		texture_y = (int)texture_pos % texture_height;
		texture_pos += game->step;
		color = *(int *)(game->img_data + texture_y
				* game->size_line + game->tex_width
				*(game->bits_per_pixel / 8));
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}

void	raycasting(t_game *game, t_vectors *player, t_map *map)
{
	t_math	math;
	int		x;

	x = 0;
	draw_ceiling_floor(game);
	while (x < WIDTH)
	{
		initialize_raycasting(&math, player, x);
		calculate_ray_direction(&math);
		initialize_step_and_side_dist(&math, player);
		perform_dda(&math, map);
		calculate_wall_dist(&math);
		calculate_line_hight_draw_start_end(&math);
		load_tex(game, &math);
		calculate_wall_hit(&math, player, game);
		draw_wall(game, &math, x);
		x++;
	}
	draw_map(game, map);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

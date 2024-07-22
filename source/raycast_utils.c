/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:42:23 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/06 21:19:10 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_tex(t_game *game, t_math *math)
{
	if (math->side == 0)
	{
		if (math->ray_dir_x > 0)
			game->img_data = mlx_get_data_addr(game->no_wall.ptr,
					&game->bits_per_pixel, &game->size_line, &game->endian);
		else
			game->img_data = mlx_get_data_addr(game->so_wall.ptr,
					&game->bits_per_pixel, &game->size_line, &game->endian);
	}
	else
	{
		if (math->ray_dir_y > 0)
			game->img_data = mlx_get_data_addr(game->ea_wall.ptr,
					&game->bits_per_pixel, &game->size_line, &game->endian);
		else
			game->img_data = mlx_get_data_addr(game->we_wall.ptr,
					&game->bits_per_pixel, &game->size_line, &game->endian);
	}
}

void	initialize_raycasting(t_math *math, t_vectors *player, int x)
{
	math->camera_x = 2 * x / (float)WIDTH - 1;
	math->ray_dir_x = player->dir_x + player->plan_x * math->camera_x;
	math->ray_dir_y = player->dir_y + player->plan_y * math->camera_x;
	math->map_x = (int)player->x;
	math->map_y = (int)player->y;
}

void	calculate_ray_direction(t_math *math)
{
	math->big_nb = 1e30;
	if (math->ray_dir_x == 0)
		math->delta_dist_x = math->big_nb;
	else
		math->delta_dist_x = fabs(1 / math->ray_dir_x);
	if (math->ray_dir_y == 0)
		math->delta_dist_y = math->big_nb;
	else
		math->delta_dist_y = fabs(1 / math->ray_dir_y);
}

void	initialize_step_and_side_dist(t_math *math, t_vectors *player)
{
	if (math->ray_dir_x < 0)
	{
		math->step_x = -1;
		math->side_dist_x = (player->x - math->map_x) * math->delta_dist_x;
	}
	else
	{
		math->step_x = 1;
		math->side_dist_x = (math->map_x + 1.0 - player->x)
			* math->delta_dist_x;
	}
	if (math->ray_dir_y < 0)
	{
		math->step_y = -1;
		math->side_dist_y = (player->y - math->map_y)
			* math->delta_dist_y;
	}
	else
	{
		math->step_y = 1;
		math->side_dist_y = (math->map_y + 1.0 - player->y)
			* math->delta_dist_y;
	}
}

void	perform_dda(t_math *math, t_map *map)
{
	math->hit = 0;
	while (math->hit == 0)
	{
		if (math->side_dist_x < math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (map->cells[math->map_x][math->map_y] == '1')
			math->hit = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:25:25 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/26 13:47:34 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_map_cell(t_game *game, int cell_x, int cell_y, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < CELL_SIZE)
	{
		y = 0;
		while (y < CELL_SIZE)
		{
			if (x == 0 || y == 0 || x == CELL_SIZE - 1 || y == CELL_SIZE - 1)
			{
				my_mlx_pixel_put(&game->img, cell_x * CELL_SIZE + x,
					cell_y * CELL_SIZE + y, BORDER_COLOR);
			}
			else
			{
				my_mlx_pixel_put(&game->img, cell_x * CELL_SIZE + x,
					cell_y * CELL_SIZE + y, color);
			}
			y++;
		}
		x++;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	draw_player(t_game *game, float start_x, float start_y)//this is bouns
{
	int	x;
	int	y;

	x = 0;
	while (x < PLAYER_SIZE)
	{
		y = 0;
		while (y < PLAYER_SIZE)
		{
			my_mlx_pixel_put(&game->img, start_x * CELL_SIZE + y,
				start_y * CELL_SIZE + x, 0xFF0000);
			y++;
		}
		x++;
	}
}

void	draw_map(t_game *game, t_map *map)
{
	int	x;
	int	y;
	int	color;

	game->start_x = max(0, game->player.y - VIEWPORT_SIZE_X / 2);
	game->start_y = max(0, game->player.x - VIEWPORT_SIZE_Y / 2);
	game->end_x = min(map->x_axis, game->start_x + VIEWPORT_SIZE_X);
	game->end_y = min(map->y_axis, game->start_y + VIEWPORT_SIZE_Y);
	y = game->start_y;
	while (y < game->end_y)
	{
		x = game->start_x;
		while (x++ < game->end_x)
		{
			if (game->map->cells[y][x] == '1')
				color = WALL_COLOR;
			else if (game->map->cells[y][x] == '0')
				color = EMPTY_SPACE_COLOR;
			draw_mini_map_cell(game, x - game->start_x,
				y - game->start_y, color);
		}
		y++;
	}
	draw_player(game, game->player.y - game->start_x,
		game->player.x - game->start_y);
}

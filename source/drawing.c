/* ************************************************************************** */
/*								                                              */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:23:11 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/10 15:26:18 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_render *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_ceiling_floor(t_game *game)
{
	int	x;
	int	y;
	int	hex_ceiling;
	int	hex_floor;

	hex_ceiling = rgb_to_hex(game->map->ceiling[0],
			game->map->ceiling[1], game->map->ceiling[2]);
	hex_floor = rgb_to_hex(game->map->floor[0],
			game->map->floor[1], game->map->floor[2]);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			my_mlx_pixel_put(&game->img, x, y, hex_ceiling);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(&game->img, x, y, hex_floor);
			y++;
		}
		x++;
	}
}

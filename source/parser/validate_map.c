/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:52:21 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 15:15:16 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	Functions

//	-> validate_map2: 
//	-> validate_map: 

void	validate_map2(t_game *game, char **map, int y, int x)
{
	if (!validate_up(game, map, y, x))
		print_error("cub3D: invalid map: not surrounded by walls1", 1, game);
	if (!validate_down(map, y, x))
		print_error("cub3D: invalid map: not surrounded by walls2", 1, game);
	if (!validate_right(map, game->map->x_axis, y, x))
		print_error("cub3D: invalid map: not surrounded by walls3", 1, game);
	if (!validate_left(game, map, y, x))
		print_error("cub3D: invalid map: not surrounded by walls4", 1, game);
}

//if there are gaps, fix
void	validate_map(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' || map[y][x] == ' ')
				x++;
			else
			{
				validate_map2(game, map, y, x);
				x++;
			}
		}
		y++;
	}
}

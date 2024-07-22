/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_CF.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:22:23 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/21 11:43:49 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Functions

//	-> check_floor: checks if key exists, if there are duplicates, stores the
//	key in the struct and then calls check_colors to validate the key

//	-> check_ceiling: checks if key exists, if there are duplicates, stores the
//	key in the struct and then calls check_colors to validate the key

//deleted free(space) in line 40 -> shouldn't make a difference
void	check_floor(t_game *game, int i)
{
	char	*space;

	space = ft_strchr(game->map->file[i], ' ');
	while (*space == ' ')
		space++;
	if (game->map->file[i][0] == 'F' && game->map->file[i][1] == ' ')
	{
		if (game->map->floor_color)
			print_error("cub3D: error: duplicate keys", 1, game);
		else if (!game->map->floor_color)
		{
			game->map->floor_color = ft_strdup(space);
			if (!game->map->floor_color)
			{
				print_error("cub3D: error: ft_strdup in floor_color failed",
					1, game);
			}
			check_colors(game, game->map->floor_color, 1);
		}
	}
}

void	check_ceiling(t_game *game, int i)
{
	char	*space;

	space = ft_strchr(game->map->file[i], ' ');
	while (*space == ' ')
		space++;
	if (game->map->file[i][0] == 'C' && game->map->file[i][1] == ' ')
	{
		if (game->map->ceiling_color)
			print_error("cub3D: error: duplicate keys", 1, game);
		else if (!game->map->ceiling_color)
		{
			game->map->ceiling_color = ft_strdup(space);
			if (!game->map->ceiling_color)
				print_error("cub3D: error: ft_strdup in ceiling_color failed",
					1, game);
			check_colors(game, game->map->ceiling_color, 0);
		}
	}
}

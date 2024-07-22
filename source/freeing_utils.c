/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:23:42 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/20 17:44:21 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	free(map->north);
	free(map->south);
	free(map->west);
	free(map->east);
	free_array(map->cells);
	free(map->floor);
	free(map->ceiling);
	free(map);
	exit(0);
}

void	free_mini_map(t_game *game)
{
	int	i;

	if (game->mini_map)
	{
		i = 0;
		while (i < game->map->y_axis)
		{
			if (game->mini_map[i])
			{
				free(game->mini_map[i]);
			}
			i++;
		}
		free(game->mini_map);
		game->mini_map = NULL;
	}
}

void	destroy_mlx_images(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->so_wall.ptr)
		mlx_destroy_image(game->mlx, game->so_wall.ptr);
	if (game->no_wall.ptr)
		mlx_destroy_image(game->mlx, game->no_wall.ptr);
	if (game->we_wall.ptr)
		mlx_destroy_image(game->mlx, game->we_wall.ptr);
	if (game->ea_wall.ptr)
		mlx_destroy_image(game->mlx, game->ea_wall.ptr);
}

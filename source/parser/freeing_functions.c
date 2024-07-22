/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:58:54 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/18 11:23:42 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	Functions

//	-> free_directions_colors: frees the allocated memory for both NSEW & colors
//	-> free_array: frees an array
//	-> free_game: frees any allocated memory in case there's an error in parsing

void	free_directions_colors(t_game *game)
{
	if (game->map->north)
		free(game->map->north);
	if (game->map->south)
		free(game->map->south);
	if (game->map->east)
		free(game->map->east);
	if (game->map->west)
		free(game->map->west);
	if (game->map->floor_color)
		free(game->map->floor_color);
	if (game->map->ceiling_color)
		free(game->map->ceiling_color);
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_game(t_game *game)
{
	if (game->map)
	{
		free_directions_colors(game);
		if (game->map->file)
			free_array(game->map->file);
		if (game->map->cells)
			free_array(game->map->cells);
		if (game->map->ceiling)
			free(game->map->ceiling);
		if (game->map->floor)
			free(game->map->floor);
	}
	free(game->map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:25:58 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/21 11:45:42 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_extras(t_game *game)
{
	if (game->map)
	{
		if (game->map->file)
			free_array(game->map->file);
		if (game->map->floor_color)
			free(game->map->floor_color);
		if (game->map->ceiling_color)
			free(game->map->ceiling_color);
	}
}

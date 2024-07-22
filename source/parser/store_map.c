/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:39:22 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 16:23:21 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	store_cells(t_game *game, int index, int i)
{
	size_t	j;

	j = -1;
	while (++j < game->map->x_axis)
	{
		if (j < ft_strlen(game->map->file[index]))
			game->map->cells[i][j] = game->map->file[index][j];
		else
			game->map->cells[i][j] = ' ';
	}
	game->map->cells[i][game->map->x_axis] = '\0';
}

void	store_map(t_game *game, int index)
{
	int	i;
	int	size;
	int	counter;

	if (!index)
		print_error("cub3D: invalid map (missing)", 1, game);
	i = -1;
	size = calculate_size(game, index);
	game->map->cells = malloc(sizeof(char *) * (size + 2));
	if (!game->map->cells)
		print_error("cub3d: malloc", 1, game);
	game->map->cells[size + 1] = NULL;
	get_map_width(game, index, size);
	counter = 0;
	while (counter <= size)
	{
		game->map->cells[++i] = malloc(sizeof(char) * game->map->x_axis + 1);
		if (!game->map->cells[i])
			print_error("cub3D: malloc fail", 1, game);
		store_cells(game, index, i);
		index++;
		counter++;
	}
}

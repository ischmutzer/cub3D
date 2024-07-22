/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:45:56 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/22 13:46:36 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	get_map_width(t_map *map)
{
	int		i;
	size_t	current_width;

	map->x_axis = 0;
	i = 0;
	while (i < map->y_axis)
	{
		current_width = ft_strlen(map->cells[i]);
		if (current_width > map->x_axis)
			map->x_axis = current_width;
		i++;
	}
} */

void	free_array_revers(char **ret, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		j++;
	}
	free(ret);
}

void	add_spaces(t_game *game, int i, size_t *j)
{
	while (*j < game->map->x_axis)
	{
		if (*j < ft_strlen (game->map->cells[i]))
			game->mini_map[i][*j] = game->map->cells[i][*j];
		else
			game->mini_map[i][*j] = ' ';
		(*j)++;
	}
}

/* void	resize_map(t_game *game)
{
	int		i;
	size_t	j;

	game->mini_map = (char **)malloc(sizeof(char *) * game->map->y_axis);
	if (!game->mini_map)
		freeing_mlx_failed(game, "Error : Failed to allocate memory\n", 1);
	i = 0;
	while (i < game->map->y_axis)
	{
		game->mini_map[i] = (char *)malloc(sizeof(char) * game->map->x_axis);
		if (!game->mini_map[i])
		{
			free_array_revers(game->mini_map, i);
			freeing_mlx_failed(game, "Error : Failed to allocate memory\n", 1);
		}
		j = 0;
		add_spaces(game, i, &j);
		i++;
	}
} */

// while (j < game->map->x_axis)
// {
// 	if (j < ft_strlen(game->map->cells[i]))
// 		game->mini_map[i][j] = game->map->cells[i][j];
// 	else
// 		game->mini_map[i][j] = ' ';
// 	j++;
// }
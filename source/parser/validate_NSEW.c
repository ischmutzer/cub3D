/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_NSEW.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:12:40 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/21 11:42:14 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_north(t_game *game, int i)
{
	char	*space;

	space = ft_strchr(game->map->file[i], ' ');
	while (*space == ' ')
		space++;
	if (game->map->file[i][0] == 'N' && game->map->file[i][1] == 'O'
		&& game->map->file[i][2] == ' ')
	{
		if (game->map->north)
			print_error("cub3D: error: duplicate keys", 1, game);
		else if (!game->map->north)
		{
			game->map->north = ft_strdup(space);
			if (!game->map->north)
				print_error("cub3D: error: ft_strdup in north failed", 1, game);
		}
	}
}

void	check_south(t_game *game, int i)
{
	char	*space;

	space = ft_strchr(game->map->file[i], ' ');
	while (*space == ' ')
		space++;
	if (game->map->file[i][0] == 'S' && game->map->file[i][1] == 'O')
	{
		if (game->map->south)
			print_error("cub3D: error: duplicate keys", 1, game);
		else if (!game->map->south)
		{
			game->map->south = ft_strdup(space);
			if (!game->map->south)
				print_error("cub3D: error: ft_strdup in south failed", 1, game);
		}
	}
}

void	check_east(t_game *game, int i)
{
	char	*space;

	space = ft_strchr(game->map->file[i], ' ');
	while (*space == ' ')
		space++;
	if (game->map->file[i][0] == 'E' && game->map->file[i][1] == 'A')
	{
		if (game->map->east)
			print_error("cub3D: error: duplicate keys", 1, game);
		else if (!game->map->east)
		{
			game->map->east = ft_strdup(space);
			if (!game->map->east)
				print_error("cub3D: error: ft_strdup in east failed", 1, game);
		}
	}
}

void	check_west(t_game *game, int i)
{
	char	*space;

	space = ft_strchr(game->map->file[i], ' ');
	while (*space == ' ')
		space++;
	if (game->map->file[i][0] == 'W' && game->map->file[i][1] == 'E')
	{
		if (game->map->west)
			print_error("cub3D: error: duplicate keys", 1, game);
		else if (!game->map->west)
		{
			game->map->west = ft_strdup(space);
			if (!game->map->west)
				print_error("cub3D: error: ft_strdup in west failed", 1, game);
		}
	}
}

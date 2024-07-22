/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:48:14 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 12:19:32 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	validate_border_walls(t_game *game, char *str)
{
	while (*str)
	{
		if (!ft_strcmp(str, ""))
			print_error("cub3D: new line found inside map", 1, game);
		if (*str == '1' || *str == ' ')
			str++;
		else
			return (0);
	}
	return (1);
}

//if (str[0] == '1' || str[0] == ' ') //&& str[str_len - 1] == '1')
// -> before was checking for first char in str and last char
static int	validate_sideborder_walls(char *str)
{
	if (str[0] == '1' || str[0] == ' ')
		return (1);
	else
		return (0);
}

// while (map[++y]) //pos 0 has already been checked with
// validate_border_wall();
static void	check_borders(t_game *game, char **map)
{
	int	y;
	int	len;

	y = 0;
	len = (count_lines(map)) - 1;
	if (!validate_border_walls(game, map[0]))
		print_error("cub3D: invalid map (not surrounded by walls)", 1, game);
	if (!validate_border_walls(game, map[len]))
		print_error("cub3D: invalid map (not surrounded by walls)", 1, game);
	while (map[++y])
	{
		if (!validate_sideborder_walls(map[y]))
			print_error("cub3D: invalid map: (not surrounded by walls)",
				1, game);
	}
}

static void	check_for_player(t_game *game, char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		print_error("cub3D: invalid map: invalid character", 1, game);
	if (!game->map->player)
		game->map->player = c;
	else
		print_error("cub3D: invalid map: player duplicate", 1, game);
}

// The map must be composed of only 6 possible characters: 0 for an empty space,
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation.
//there cannot be duplicates of player
void	check_map(t_game *game, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		if (!ft_strcmp(map[y], ""))
			print_error("cub3d: invalid map: map separeted by empty new line\n",
				1, game);
		check_borders(game, map);
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '1' || map[y][x] == ' ')
				x++;
			else
			{
				check_for_player(game, map[y][x]);
				game->map->x = x;
				game->map->y = y;
				x++;
			}
		}
	}
}

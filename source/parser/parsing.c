/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:48:07 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/22 16:16:04 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <strings.h>
//#include <memory>

//const char	*valid_identifiers[] = {"NO", "SO", "EA", "WE", "F", "C"};

static int	check_for_map(char *str)
{
	int	has_digit;

	has_digit = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			has_digit = 1;
			str++;
		}
		else if (*str == ' ')
			str++;
		else
			return (0);
	}
	return (has_digit);
}

static void	check_keys2(t_game *game, int i)
{
	if (game->map->file[i][0] == 'N' && game->map->file[i][1] == 'O'
		&& game->map->file[i][2] == ' ')
		check_north(game, i);
	else if (game->map->file[i][0] == 'S' && game->map->file[i][1] == 'O'
		&& game->map->file[i][2] == ' ')
		check_south(game, i);
	else if (game->map->file[i][0] == 'E' && game->map->file[i][1] == 'A'
		&& game->map->file[i][2] == ' ')
		check_east(game, i);
	else if (game->map->file[i][0] == 'W' && game->map->file[i][1] == 'E'
		&& game->map->file[i][2] == ' ')
		check_west(game, i);
	else if (game->map->file[i][0] == 'F' && game->map->file[i][1] == ' ')
		check_floor(game, i);
	else if (game->map->file[i][0] == 'C' && game->map->file[i][1] == ' ')
		check_ceiling(game, i);
	else
	{
		if (!game->map->map)
			print_error("cub3D: invalid key", 1, game);
	}
}

static void	check_keys(t_game *game)
{
	int	i;

	i = -1;
	while (game->map->file[++i])
	{
		if (!ft_strcmp(game->map->file[i], ""))
			continue ;
		if (!game->map->map && check_for_map(game->map->file[i]))
			game->map->map = i;
		if (!game->map->map && game->map->file[i][0] == ' ')
			print_error("cub3D: error: invalid space before key", 1, game);
		if (!game->map->map)
			is_trailing_space(game, game->map->file[i]);
		check_keys2(game, i);
	}
	if (!game->map->north || !game->map->south || !game->map->east
		|| !game->map->west || !game->map->floor_color
		|| !game->map->ceiling_color)
		print_error("cub3D: missing keys", 1, game);
}

//map content needs to be last
void	parser(t_game *game, char *file)
{
	check_file(file, game);
	check_keys(game);
	check_textures(game);
	store_map(game, game->map->map);
	game->map->y_axis = count_lines(game->map->cells);
	check_map(game, game->map->cells);
	if (!game->map->player)
		print_error("cub3d: player missing", 1, game);
	validate_map(game, game->map->cells);
	convert_space_to_wall(game);
	free_extras(game);
}

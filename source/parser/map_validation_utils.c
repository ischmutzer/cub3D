/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:58:02 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 15:52:45 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

//	Functions

//	-> convert_space_to_wall: converts any space into a '1'

//	-> read_file: reads the configuration file and returns an array with it

//	-> delete_empty_line_at_end: deletes any empty lines found after the map
//	is finsihed, it's used in by calculate_size

//	-> calculate_size: calculates net amount the array needs to hold the map
//	excluding an extra line for NULL termiantor & one more bc the amount is
//	calculated from 0-upwards

//	-> store_map: extracts the map from the config file and stores it in cells

void	convert_space_to_wall(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->cells[++i])
	{
		j = -1;
		while (game->map->cells[i][++j])
		{
			if (game->map->cells[i][j] == ' ')
				game->map->cells[i][j] = '1';
		}
	}
}

char	**read_file(t_game *game, int fd, char *read, char *full)
{
	char	**file;
	char	*tmp;

	read = get_next_line(fd, 0);
	if (!read)
		print_error("cub3D: empty file", 1, game);
	full = NULL;
	while (read)
	{
		tmp = full;
		full = ft_strjoin(full, read);
		free(tmp);
		free(read);
		if (!full)
		{
			get_next_line(fd, 1);
			print_error("error", 1, game);
		}
		read = get_next_line(fd, 0);
	}
	file = ft_split(full, '\n');
	free(full);
	if (!file)
		print_error("cub3D: error: read_file: split failed", 1, game);
	return (file);
}

static int	delete_empty_line_at_end(char **map, int index)
{
	int	end;
	int	counter;

	counter = 0;
	end = index;
	while (map[end])
		end++;
	while (end >= index)
	{
		if (!ft_strcmp(map[end], ""))
		{
			counter++;
			end--;
		}
		else
			break ;
	}
	return (counter);
}

int	calculate_size(t_game *game, int index)
{
	int	size;
	int	end;

	size = count_lines(game->map->file) - index;
	end = delete_empty_line_at_end(game->map->file, index);
	size -= end;
	return (size);
}

void	get_map_width(t_game *game, int index, int size)
{
	int		i;
	size_t	current_width;

	game->map->x_axis = 0;
	i = 0;
	while (i < size)
	{
		current_width = ft_strlen(game->map->file[index]);
		if (current_width > game->map->x_axis)
			game->map->x_axis = current_width;
		i++;
		index++;
	}
}

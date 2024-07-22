/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:34 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/18 16:00:35 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>
#include <string.h>

//	Functions

//	-> check_file: checks that the configuration file exists and stores it in
//	the struct
//	-> check_for_hidden_files: compares the texture file name against ".xpm"
//	to check for hidden files
//	-> check_textures: checks whether the texture exists and that it isn't a
//	hidden file

void	check_file(char *file, t_game *game)
{
	int		fd;
	char	*read;
	char	*full;

	read = NULL;
	full = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("cub3D: error: invalid file", 1, game);
	game->map->file = read_file(game, fd, read, full);
	close (fd);
}

static void	check_for_hidden_files(t_game *game, char *str)
{
	char	*file;

	file = ft_strrchr(str, '/');
	if (!file)
		print_error("cub3D: allocation failed", 1, game);
	file++;
	if (!ft_strcmp(file, ".xpm"))
		print_error("cub3D: texture is hidden file", 1, game);
}

static void	check_for_xpm(t_game *game, char *str)
{
	char	*search;

	search = ft_strnstr(str, ".xpm", ft_strlen(str));
	if (search == NULL)
		print_error("cub3D: invalid texture", 1, game);
}

void	check_textures(t_game *game)
{
	if (open(game->map->north, O_RDONLY) == -1)
		print_error("cub3D: error: invalid texture", 1, game);
	check_for_hidden_files(game, game->map->north);
	check_for_xpm(game, game->map->north);
	if (open(game->map->south, O_RDONLY) == -1)
		print_error("cub3D: error: invalid texture", 1, game);
	check_for_hidden_files(game, game->map->south);
	check_for_xpm(game, game->map->south);
	if (open(game->map->west, O_RDONLY) == -1)
		print_error("cub3D: error: invalid texture", 1, game);
	check_for_hidden_files(game, game->map->west);
	check_for_xpm(game, game->map->west);
	if (open(game->map->east, O_RDONLY) == -1)
		print_error("cub3D: error: invalid texture", 1, game);
	check_for_hidden_files(game, game->map->east);
	check_for_xpm(game, game->map->east);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:36:01 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/17 18:15:00 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	Functions

//	-> validate_commas: checks that there is a max of 2 commas in the color
//	-> store_color_in_int: converts the color str into an int and stores it in
//	an int array
//	-> check_colors2: continuation of check_colors. Checks that they have the
//	RGB format
//	-> check_colors: validates the colors ans stores them in the struct

static void	validate_commas(t_game *game, char *color)
{
	int	i;

	i = 0;
	while (*color)
	{
		if (*color == ',')
			i++;
		color++;
	}
	if (i > 2)
		print_error("cub3D: invalid color", 1, game);
}

static int	*store_color_in_int(t_game *game, char **color)
{
	int	*colors;
	int	i;

	colors = malloc(sizeof(int) * 3);
	if (!colors)
	{
		free_array(color);
		print_error("cub3D: malloc fail", 1, game);
	}
	i = -1;
	while (++i <= 2)
		colors[i] = ft_atoi(color[i]);
	free_array(color);
	return (colors);
}

static void	check_colors2(t_game *game, char **tmp)
{
	int	i;
	int	j;
	int	num;

	i = -1;
	while (tmp[++i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] > 57 || tmp[i][j] < 48)
			{
				free_array(tmp);
				print_error("cub3D: error: invalid color", 1, game);
			}
			j++;
		}
		num = ft_atoi(tmp[i]);
		if (num > 255 || num < 0)
		{
			free_array(tmp);
			print_error("cub3D: error: invalid color", 1, game);
		}
	}
}

void	check_colors(t_game *game, char *color, int flag)
{
	char	**tmp;
	int		i;

	i = 0;
	validate_commas(game, color);
	tmp = ft_split(color, ',');
	if (!tmp)
		print_error("cub3D: error: split failed", 1, game);
	while (tmp[i])
		i++;
	if (i != 3)
	{
		free_array(tmp);
		print_error("cub3D: error: invalid color", 1, game);
	}
	check_colors2(game, tmp);
	if (flag)
		game->map->floor = store_color_in_int(game, tmp);
	if (!flag)
		game->map->ceiling = store_color_in_int(game, tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_up_down_right_left.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:56:54 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 15:45:29 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	Functions

//	-> validate_up:
//	-> validate_down:
//	-> validate_right:
//	-> validate_left:

int	validate_up(t_game *game, char **map, int y, int x)
{
	(void)game;
	if (y == 0)
		y++;
	while (y > 0)
	{
		if (map[y][x] == ' ' || map[y][x] == '\n')
			return (0);
		if (map[y][x] == '1')
			return (1);
		else
			y--;
	}
	if (map[y][x] == '1')
		return (1);
	return (0);
}

int	validate_down(char **map, int y, int x)
{
	int	height;

	height = count_lines(map);
	while (y < height)
	{
		if (map[y][x] == ' ' || map[y][x] == '\n')
			return (0);
		if (map[y][x] == '1')
			return (1);
		else
			y++;
	}
	return (0);
}

int	validate_right(char **map, int x_axis, int y, int x)
{
	while (x <= x_axis)
	{
		if (map[y][x] == ' ' || map[y][x] == '\n')
			return (0);
		if (map[y][x] == '1')
			return (1);
		else
			x++;
	}
	return (0);
}

int	validate_left(t_game *game, char **map, int y, int x)
{
	(void)game;
	if (x == 0 && map[y][x] != '1')
		return (1);
	while (x >= 0)
	{
		if (map[y][x] == ' ' || map[y][x] == '\n')
			return (0);
		if (map[y][x] == '1')
			return (1);
		else
			x--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:54:43 by ischmutz          #+#    #+#             */
/*   Updated: 2024/07/22 15:43:06 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// 	Functions:

//	-> print_error: prints an error message to fd 2 and frees any allocated
//	memory
//	-> is_space: checks whether a char is a ' ', it's used by is_trailing_space
//	-> is_trailing_space: checks for trailing spaces
//	-> count_lines: counts how many elements an array has. (calculates y-axis)
//	-> ft_strcmp: compares two strings until '\0'

void	print_error(char *str, int status, t_game *game)
{
	(void)game;
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	free_game(game);
	exit(status);
}

static int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

void	is_trailing_space(t_game *game, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (is_space(str[len - 1]))
		print_error("cub3D: trailing space", 1, game);
}

int	count_lines(char **config_file)
{
	int	i;

	i = 0;
	while (config_file[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (s1[i] - s2[i]);
}

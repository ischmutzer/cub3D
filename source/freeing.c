/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:34:28 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/20 17:44:54 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_stage_1(t_game *game, char *str)
{
	ft_putstr_fd(str, 2);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
}

void	free_stage_2(t_game *game, char *str)
{
	ft_putstr_fd(str, 2);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_mini_map(game);
	free_map(game->map);
}

void	free_stage_3(t_game *game, char *str)
{
	ft_putstr_fd(str, 2);
	destroy_mlx_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_mini_map(game);
	free_map(game->map);
}

void	free_stage_4(t_game *game, char *str)
{
	printf("End Game\n%s\n", str);
	destroy_mlx_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_mini_map(game);
	free_map(game->map);
}

void	freeing_mlx_failed(t_game *game, char *str, int stage)
{
	if (stage == 1)
		free_stage_1(game, str);
	else if (stage == 2)
		free_stage_2(game, str);
	else if (stage == 3)
		free_stage_3(game, str);
	else if (stage == 4)
		free_stage_4(game, str);
}

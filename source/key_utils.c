/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:27:32 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/06 20:33:19 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d_pressed(t_game *game)
{
	t_map		*map;
	t_vectors	*player;
	int			newx;
	int			newy;

	map = game->map;
	player = &game->player;
	if (game->key.d)
	{
		d_rotate_player(player);
		newx = (int)(player->x + player->plan_x * (0.5));
		newy = (int)(player->y);
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->x += player->plan_x * PLY_S;
		newx = (int)(player->x);
		newy = (int)(player->y + player->plan_y * (0.5));
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->y += player->plan_y * PLY_S;
		d_update(player);
	}
}

void	d_rotate_player(t_vectors *player)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT_S)
		- player->dir_y * sin(-ROT_S);
	player->dir_y = old_dir_x * sin(-ROT_S)
		+ player->dir_y * cos(-ROT_S);
	old_plan_x = player->plan_x;
	player->plan_x = player->plan_x * cos(-ROT_S)
		- player->plan_y * sin(-ROT_S);
	player->plan_y = old_plan_x * sin(-ROT_S)
		+ player->plan_y * cos(-ROT_S);
}

void	d_update(t_vectors *player)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_S)
		- player->dir_y * sin(ROT_S);
	player->dir_y = old_dir_x * sin(ROT_S)
		+ player->dir_y * cos(ROT_S);
	old_plan_x = player->plan_x;
	player->plan_x = player->plan_x * cos(ROT_S)
		- player->plan_y * sin(ROT_S);
	player->plan_y = old_plan_x * sin(ROT_S)
		+ player->plan_y * cos(ROT_S);
}

void	a_rotate_player(t_vectors *player)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_S)
		- player->dir_y * sin(ROT_S);
	player->dir_y = old_dir_x * sin(ROT_S)
		+ player->dir_y * cos(ROT_S);
	old_plan_x = player->plan_x;
	player->plan_x = player->plan_x * cos(ROT_S)
		- player->plan_y * sin(ROT_S);
	player->plan_y = old_plan_x * sin(ROT_S)
		+ player->plan_y * cos(ROT_S);
}

void	a_update(t_vectors *player)
{
	float	old_dir_x;
	float	old_plan_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT_S)
		- player->dir_y * sin(-ROT_S);
	player->dir_y = old_dir_x * sin(-ROT_S)
		+ player->dir_y * cos(-ROT_S);
	old_plan_x = player->plan_x;
	player->plan_x = player->plan_x * cos(-ROT_S)
		- player->plan_y * sin(-ROT_S);
	player->plan_y = old_plan_x * sin(-ROT_S)
		+ player->plan_y * cos(-ROT_S);
}

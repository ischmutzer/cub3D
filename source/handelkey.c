/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:58:59 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/06 21:42:27 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_pressed(t_game *game)
{
	t_map		*map;
	t_vectors	*player;
	int			newx;
	int			newy;

	map = game->map;
	player = &game->player;
	if (game->key.w)
	{
		newx = (int)(player->x + player->dir_x * (0.5));
		newy = (int)(player->y);
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->x += player->dir_x * PLY_S;
		newx = (int)(player->x);
		newy = (int)(player->y + player->dir_y * (0.5));
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->y += player->dir_y * PLY_S;
	}
}

void	s_pressed(t_game *game)
{
	t_map		*map;
	t_vectors	*player;
	int			newx;
	int			newy;

	map = game->map;
	player = &game->player;
	if (game->key.s)
	{
		newx = (int)(player->x - player->dir_x * (0.5));
		newy = (int)(player->y);
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->x -= player->dir_x * PLY_S ;
		newx = (int)(player->x);
		newy = (int)(player->y - player->dir_y * (0.5));
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->y -= player->dir_y * PLY_S;
	}
}

void	left_pressed(t_game *game )
{
	float	old_dir_x;
	float	old_plan_x;

	if (game->key.left || game->key.mouse_left)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROT_S)
			- game->player.dir_y * sin(ROT_S);
		game->player.dir_y = old_dir_x * sin(ROT_S)
			+ game->player.dir_y * cos(ROT_S);
		old_plan_x = game->player.plan_x;
		game->player.plan_x = game->player.plan_x * cos(ROT_S)
			- game->player.plan_y * sin(ROT_S);
		game->player.plan_y = old_plan_x * sin(ROT_S)
			+ game->player.plan_y * cos(ROT_S);
	}
}

void	right_pressed(t_game *game)
{
	float	old_dir_x;
	float	old_plan_x;

	if (game->key.right || game->key.mouse_right)
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROT_S)
			- game->player.dir_y * sin(-ROT_S);
		game->player.dir_y = old_dir_x * sin(-ROT_S)
			+ game->player.dir_y * cos(-ROT_S);
		old_plan_x = game->player.plan_x;
		game->player.plan_x = game->player.plan_x * cos(-ROT_S)
			- game->player.plan_y * sin(-ROT_S);
		game->player.plan_y = old_plan_x * sin(-ROT_S)
			+ game->player.plan_y * cos(-ROT_S);
	}
}

void	a_pressed(t_game *game)
{
	t_map		*map;
	t_vectors	*player;
	int			newx;
	int			newy;

	map = game->map;
	player = &game->player;
	if (game->key.a)
	{
		a_rotate_player(player);
		newx = (int)(player->x - player->plan_x * (0.5));
		newy = (int)(player->y);
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->x -= player->plan_x * PLY_S;
		newx = (int)(player->x);
		newy = (int)(player->y - player->plan_y * (0.5));
		if (newx >= 0 && newx < WIDTH && newy >= 0 && newy < HEIGHT)
			if (map->cells[newx][newy] == '0')
				player->y -= player->plan_y * PLY_S ;
		a_update(player);
	}
}

/* void w_pressed(t_game *game, doubel delta_time)
{
	t_map *map;
	t_vectors *player;

	map = game->map;
	player = &game->player;
	if (game->key.w)
	{
		if (map->cells[(int)(player->x + player->dir_x * (0.5))]
			&& map->cells[(int)(player->x + player->dir_x * (1))]
			[(int)(player->y)] == '0')
			player->x += player->dir_x * PLY_S * delta_time;
		if (map->cells[(int)(player->x)]
			&& map->cells[(int)(player->x)]
			[(int)(player->y + player->dir_y * (0.5))] == '0')
			player->y += player->dir_y * PLY_S * delta_time;
		raycasting(game, &game->player, game->map);
	}
} */
/* void s_pressed(t_game *game , double delta_time)
{
	t_vectors *player;
	t_map *map;

	map = game->map;
	player = &game->player;
	if (game->key.s)
	{
		if (map->cells[(int)(player->x - player->dir_x * (0.5))]
			&& map->cells[(int)(player->x - player->dir_x * (0.5))]
			[(int)(player->y)] == '0')
			player->x -= player->dir_x * PLY_S * delta_time;
		if (map->cells[(int)(player->x)]
			&& map->cells[(int)(player->x)]
			[(int)(player->y - player->dir_y * (0.5))] == '0')
			player->y -= player->dir_y * PLY_S * delta_time;
		raycasting(game, &game->player, game->map);
	}
} */

/* void d_pressed(t_game *game, double delta_time)
{
    t_map *map;
    t_vectors *player;

    map = game->map;
    player = &game->player;
    if (game->key.d)
    {
        d_rotate_player(player, delta_time);
        if (map->cells[(int)(player->x + player->plan_x * (0.5))]
			&& map->cells[(int)(player->x + player->plan_x * (0.5))]
            [(int)(player->y)] == '0')
            player->x += player->plan_x * PLY_S * delta_time;
        if (map->cells[(int)(player->x)]
			&& map->cells[(int)(player->x)] [(int)(player->y
				+ player->plan_y * (0.5))] == '0')
            player->y += player->plan_y * PLY_S * delta_time;
        d_update(player, delta_time);
        raycasting(game, &game->player, game->map);
    }
    
} */
/* void    a_pressed(t_game *game, double delta_time)
{
    t_map *map;
    t_vectors *player;


    map = game->map;
    player = &game->player;
    if (game->key.a)
    {
        a_rotate_player(player, delta_time);
        if (map->cells[(int)(player->x - player->plan_x * (0.5))]
            && map->cells[(int)(player->x - player->plan_x * (0.5))]
            [(int)(player->y)] == '0')
            player->x -= player->plan_x * PLY_S * delta_time;
        if (map->cells[(int)(player->x)]
            && map->cells[(int)(player->x)]
            [(int)(player->y - player->plan_y * (0.5))] == '0')
            player->y -= player->plan_y * PLY_S * delta_time;
        a_update(player, delta_time);
        raycasting(game, &game->player, game->map);
    }
}
 */
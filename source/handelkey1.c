/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelkey1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:01:36 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/20 17:46:40 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_game *game)
{
	w_pressed(game);
	s_pressed(game);
	a_pressed(game);
	d_pressed(game);
	left_pressed(game);
	right_pressed(game);
	raycasting(game, &game->player, game->map);
	return (0);
}

int	close_game(t_game *game)
{
	freeing_mlx_failed(game, "Thanks :)", 4);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key.w = 1;
	else if (keycode == 115)
		game->key.s = 1;
	else if (keycode == 100)
		game->key.d = 1;
	else if (keycode == 97)
		game->key.a = 1;
	else if (keycode == 0xff53)
		game->key.right = 1;
	else if (keycode == 0xff51)
		game->key.left = 1;
	else if (keycode == 65307)
		close_game(game);
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == 119)
		game->key.w = 0;
	else if (keycode == 115)
		game->key.s = 0;
	else if (keycode == 100)
		game->key.d = 0;
	else if (keycode == 97)
		game->key.a = 0;
	else if (keycode == XK_Right)
		game->key.right = 0;
	else if (keycode == XK_Left)
		game->key.left = 0;
	return (0);
}

int	handle_mouse(int x, int y, t_game *game)
{
	int	fifth_width;

	(void)y;
	game->key.mouse_left = 0;
	game->key.mouse_right = 0;
	fifth_width = WIDTH / 5;
	if (x < 2 * fifth_width)
		game->key.mouse_left = 1;
	else if (x > 3 * fifth_width)
		game->key.mouse_right = 1;
	return (0);
}

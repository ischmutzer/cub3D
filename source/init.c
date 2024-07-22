/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:06:40 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/20 17:48:07 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_direction(t_game *game)
{
	game->player.x = game->map->y + 0.5;
	game->player.y = game->map->x + 0.5;
	game->map->cells[(int)game->player.x][(int)game->player.y] = '0';
	if (game->map->player == 'W')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map->player == 'S')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->map->player == 'E')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map->player == 'N')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}

void	player_plan(t_game *game)
{
	if (game->map->player == 'W')
	{
		game->player.plan_x = -0.66;
		game->player.plan_y = 0;
	}
	else if (game->map->player == 'S')
	{
		game->player.plan_x = 0;
		game->player.plan_y = 0.66;
	}
	else if (game->map->player == 'E')
	{
		game->player.plan_x = 0.66;
		game->player.plan_y = 0;
	}
	else if (game->map->player == 'N')
	{
		game->player.plan_x = 0;
		game->player.plan_y = -0.66;
	}
}

void	puting_imges(t_game *game)
{
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	game->no_wall.ptr = mlx_xpm_file_to_image(game->mlx, game->map->north,
			&game->no_wall.width, &game->no_wall.height);
	if (!game->no_wall.ptr || game->no_wall.width != 64
		|| game->no_wall.height != 64)
		freeing_mlx_failed(game, "Error : Invalid texture\n", 3);
	game->so_wall.ptr = mlx_xpm_file_to_image(game->mlx, game->map->south,
			&game->so_wall.width, &game->so_wall.height);
	if (!game->so_wall.ptr || game->so_wall.width != 64
		|| game->so_wall.height != 64)
		freeing_mlx_failed(game, "Error : Invalid textrue\n", 3);
	game->we_wall.ptr = mlx_xpm_file_to_image(game->mlx, game->map->west,
			&game->we_wall.width, &game->we_wall.height);
	if (!game->we_wall.ptr || game->we_wall.width != 64
		|| game->we_wall.height != 64)
		freeing_mlx_failed(game, "Error : Invalid texture\n", 3);
	game->ea_wall.ptr = mlx_xpm_file_to_image(game->mlx, game->map->east,
			&game->ea_wall.width, &game->ea_wall.height);
	if (!game->ea_wall.ptr || game->ea_wall.width != 64
		|| game->ea_wall.height != 64)
		freeing_mlx_failed(game, "Error : Invalid texture\n", 3);
}

void	init_game(t_game *game)
{
	player_direction(game);
	player_plan(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		free_map(game->map);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "3D World");
	if (!game->win)
		freeing_mlx_failed(game, "Erorr : Failed to create a window\n", 1);
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		freeing_mlx_failed(game, "Erorr : Failed to create an imge \n", 2);
	puting_imges(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:53:32 by amalkhal          #+#    #+#             */
/*   Updated: 2024/07/20 18:12:50 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file_name(char *str)
{
	char	*file_name;

	file_name = ft_strrchr(str, '/');
	if (!file_name)
		return (0);
	file_name++;
	if (!ft_strcmp(file_name, ".cub"))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	game.map = malloc(sizeof(t_map));
	if (!game.map)
	{
		ft_putstr_fd("cub3D: error: malloc failed\n", 2);
		exit(1);
	}
	ft_bzero(game.map, sizeof(t_map));
	if (argc != 2)
		print_error("cub3D: error: invalid number of arguments", 1, &game);
	else if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		print_error("cub3D: error: invalid extension", 1, &game);
	else if (!check_file_name(argv[1]))
		print_error("cub3D: invalid file name", 1, &game);
	parser(&game, argv[1]);
	init_game(&game);
	raycasting(&game, &game.player, game.map);
	mlx_hook(game.win, 2, (1L << 0), &handle_keypress, &game);
	mlx_hook(game.win, 3, (1L << 1), &handle_keyrelease, &game);
	mlx_hook(game.win, 6, (1L << 6), &handle_mouse, &game);
	mlx_hook(game.win, 17, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
}

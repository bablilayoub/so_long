/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:02:42 by abablil           #+#    #+#             */
/*   Updated: 2023/12/26 20:00:17 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 53)
		game->game_over++;
	else if (keycode == 13 || keycode == 126)
		handle_w_key(game);
	else if (keycode == 1 || keycode == 125)
		handle_s_key(game);
	else if (keycode == 2 || keycode == 124)
		handle_d_key(game);
	else if (keycode == 0 || keycode == 123)
		handle_a_key(game);
	if (game->game_over > 0)
		close_game(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	render_map(game);
	return (0);
}

void	start_making(t_data *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			ITEM_SIZE * game->width, ITEM_SIZE * game->height, GAME_NAME);
	render_image(game);
	render_map(game);
	mlx_hook(game->mlx_win, 17, 0, close_game, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_loop_hook(game->mlx, spawn_enemy, game);
	mlx_loop(game->mlx);
}

void	init_game(char *map_name, t_data *game)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		send_error("No such file or directory!\n", game);
	parse_map(fd, game);
	start_making(game);
}
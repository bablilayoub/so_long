/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:02:42 by abablil           #+#    #+#             */
/*   Updated: 2024/01/03 10:25:28 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (keycode == 14)
		handle_e_key(game);
	if (game->game_over > 0)
		close_game(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	render_map(game);
	render_moves_and_collected(game);
	return (0);
}

void	start_making(t_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		send_error("Faild to init mlx", game);
	if (ITEM_SIZE <= 0)
		send_error("Item size can't be under or equal to 0.", game);
	game->mlx_win = mlx_new_window(game->mlx,
			ITEM_SIZE * game->width, ITEM_SIZE * game->height + 50, GAME_NAME);
	if (!game->mlx_win)
		send_error("Failed to create new mlx window", game);
	render_image(game);
	render_map(game);
	mlx_hook(game->mlx_win, 17, 0, close_game, game);
	mlx_hook(game->mlx_win, 2, 0, key_hook, game);
	mlx_loop_hook(game->mlx, handle_enemy, game);
	render_moves_and_collected(game);
	mlx_loop(game->mlx);
}

void	init_game(char *map_name, t_data *game)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	free(map_name);
	if (fd == -1)
		send_error("No such file or directory!\n", game);
	parse_map(fd, game);
	close(fd);
	start_making(game);
}

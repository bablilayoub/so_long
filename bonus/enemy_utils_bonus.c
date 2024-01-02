/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:39:07 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 18:22:17 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_left(t_data *game, int i)
{
	static int	count = 0;

	game->map_items[i] = '0';
	game->map_items[i - 1] = 'X';
	count++;
	if (count == 1)
		game->enemy = game->enemy_left_1;
	if (count == 2)
		game->enemy = game->enemy_left_2;
	if (count == 3)
		game->enemy = game->enemy_left_3;
	if (count == 4)
		game->enemy = game->enemy_left_4;
	if (count == 5)
		game->enemy = game->enemy_left_5;
	if (count == 6)
		game->enemy = game->enemy_left_6;
	if (count == 7)
	{
		game->enemy = game->enemy_left_7;
		count = 0;
	}
}

void	move_enemy_right(t_data *game, int i)
{
	static int	count = 0;

	game->map_items[i] = '0';
	game->map_items[i + 1] = 'X';
	count++;
	if (count == 1)
		game->enemy = game->enemy_right_1;
	if (count == 2)
		game->enemy = game->enemy_right_2;
	if (count == 3)
		game->enemy = game->enemy_right_3;
	if (count == 4)
		game->enemy = game->enemy_right_4;
	if (count == 5)
		game->enemy = game->enemy_right_5;
	if (count == 6)
		game->enemy = game->enemy_right_6;
	if (count == 7)
	{
		game->enemy = game->enemy_right_7;
		count = 0;
	}
}

void	move_enemy_up_and_down(t_data *game, int i, int where)
{
	game->map_items[i] = '0';
	game->map_items[where] = 'X';
	game->enemy = game->enemy_left_1;
}

void	game_over(t_data *game, int i)
{
	game->map_items[i] = '0';
	game->game_over++;
	ft_printf("I got you bro :) !!\n");
	close_game(game);
}

void	render_enemy_left(t_data *game, int h_w)
{
	game->enemy_left_1 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_1.xpm", &h_w, &h_w);
	game->enemy_left_2 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_2.xpm", &h_w, &h_w);
	game->enemy_left_3 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_3.xpm", &h_w, &h_w);
	game->enemy_left_4 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_4.xpm", &h_w, &h_w);
	game->enemy_left_4 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_4.xpm", &h_w, &h_w);
	game->enemy_left_5 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_5.xpm", &h_w, &h_w);
	game->enemy_left_6 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_6.xpm", &h_w, &h_w);
	game->enemy_left_7 = mlx_xpm_file_to_image(game->mlx,
			"../textures/enemy_left_7.xpm", &h_w, &h_w);
}

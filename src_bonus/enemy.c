/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:20:39 by abablil           #+#    #+#             */
/*   Updated: 2023/12/26 21:57:42 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int spawn_enemy(t_data *game)
{
	static int already_spawned;
	static int go_back = 0;
	static int count = 1500;
	int i;
	int temp = 0;

	count--;
	if (count != 0)
		return 0;
	else
		count = 1500;
	i = 0;
	if (!already_spawned)
	{
		already_spawned = 1;
		while (game->map_items[i] && game->map_items[i] != 'C')
			i++;
		temp = i;
		while (game->map_items[i] && game->map_items[i] != '0')
			i++;
		if (i == temp)
		{
			while (game->map_items[i] && game->map_items[i] != '0')
				i--;
		}
		game->map_items[i] = 'X';
	}
	else if (already_spawned)
	{
		while (game->map_items[i] != 'X')
			i++;
		if (game->map_items[i - 1] == 'P')
		{
			game->map_items[i] = '0';
			game->map_items[i - 1] = 'X';
			game->game_over++;
			ft_printf("I got you bro :) !!\n");
			close_game(game);
		}
		if (game->map_items[i + 1] == 'P')
		{
			game->map_items[i] = '0';
			game->map_items[i + 1] = 'X';
			game->game_over++;
			ft_printf("I got you bro :) !!\n");
			close_game(game);
		}
		if (game->map_items[i + 1] == '0' && !go_back)
		{
			game->map_items[i] = '0';
			game->map_items[i + 1] = 'X';
			game->enemy = game->enemy_right;
		}
		else if (game->map_items[i - 1] == '0')
		{
			go_back = 1;
			game->map_items[i] = '0';
			game->map_items[i - 1] = 'X';
			game->enemy = game->enemy_left;
		}
		else if (game->map_items[i - game->width] == '0' && !go_back)
		{
			go_back = 1;
			game->map_items[i] = '0';
			game->map_items[i - game->width] = 'X';
			game->enemy = game->enemy_left;
		}
		else if (game->map_items[i + game->width] == '0' && !go_back)
		{
			go_back = 1;
			game->map_items[i] = '0';
			game->map_items[i + game->width] = 'X';
			game->enemy = game->enemy_left;
		}
		else
			go_back = 0;
	}
	render_map(game);
	return 0;
}
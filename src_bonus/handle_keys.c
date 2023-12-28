/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:35:51 by abablil           #+#    #+#             */
/*   Updated: 2023/12/28 10:13:47 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_w_key(t_data *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map_items[i] != 'P')
		i++;
	check_exit_and_enemy(game, game->map_items[i - x]);
	if (!check_for_portals(game, game->map_items[i - x]))
	{
		if (game->map_items[i - x] != '1' && game->map_items[i - x] != 'E')
		{
			if (game->map_items[i - x] == 'C')
				game->collected++;
			game->map_items[i] = '0';
			game->map_items[i - x] = 'P';
			game->player = game->player_top;
			game->steps++;
		}
	}
}

void	handle_s_key(t_data *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map_items[i] != 'P')
		i++;
	check_exit_and_enemy(game, game->map_items[i + x]);
	if (!check_for_portals(game, game->map_items[i + x]))
	{
		if (game->map_items[i + x] != '1' && game->map_items[i + x] != 'E')
		{
			if (game->map_items[i + x] == 'C')
				game->collected++;
			game->map_items[i] = '0';
			game->map_items[i + x] = 'P';
			game->player = game->player_right;
			game->steps++;
		}
	}
}

void	handle_d_key(t_data *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map_items[i] != 'P')
		i++;
	check_exit_and_enemy(game, game->map_items[i + 1]);
	if (!check_for_portals(game, game->map_items[i + 1]))
	{
		if (game->map_items[i + 1] != '1' && game->map_items[i + 1] != 'E')
		{
			if (game->map_items[i + 1] == 'C')
				game->collected++;
			game->map_items[i] = '0';
			game->map_items[i + 1] = 'P';
			game->player = game->player_right;
			game->steps++;
		}
	}
}

void	handle_a_key(t_data *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map_items[i] != 'P')
		i++;
	check_exit_and_enemy(game, game->map_items[i - 1]);
	if (!check_for_portals(game, game->map_items[i - 1]))
	{
		if (game->map_items[i - 1] != '1' && game->map_items[i - 1] != 'E')
		{
			if (game->map_items[i - 1] == 'C')
				game->collected++;
			game->map_items[i] = '0';
			game->map_items[i - 1] = 'P';
			game->player = game->player_left;
			game->steps++;
		}
	}
}

void	handle_e_key(t_data *game)
{
	static int	spawed = 0;

	if (!spawed)
	{
		spawed = 1;
		spawn_portals(game);
	}
	else
	{
		spawed = 0;
		destroy_portals(game);
	}
}

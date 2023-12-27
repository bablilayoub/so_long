/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:39:07 by abablil           #+#    #+#             */
/*   Updated: 2023/12/27 06:43:40 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_left(t_data *game, int i)
{
	game->map_items[i] = '0';
	game->map_items[i - 1] = 'X';
	game->enemy = game->enemy_left;
}

void	move_enemy_right(t_data *game, int i)
{
	game->map_items[i] = '0';
	game->map_items[i + 1] = 'X';
	game->enemy = game->enemy_right;
}

void	move_enemy_up(t_data *game, int i)
{
	game->map_items[i] = '0';
	game->map_items[i - game->width] = 'X';
	game->enemy = game->enemy_left;
}

void	move_enemy_down(t_data *game, int i)
{
	game->map_items[i] = '0';
	game->map_items[i + game->width] = 'X';
	game->enemy = game->enemy_left;
}

void	game_over(t_data *game, int i)
{
	game->map_items[i] = '0';
	game->game_over++;
	ft_printf("I got you bro :) !!\n");
	close_game(game);
}

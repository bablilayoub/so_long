/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:35:51 by abablil           #+#    #+#             */
/*   Updated: 2023/12/27 01:47:26 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_data *game, char position)
{
	if (position == 'E' && game->collectables == game->collected)
	{
		game->game_over++;
		game->steps++;
		ft_printf("Moves: %d\n", game->steps);
		ft_printf("You Win !!\n");
	}
}

void	handle_w_key(t_data *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map_items[i] != 'P')
		i++;
	check_exit(game, game->map_items[i - x]);
	if (game->map_items[i - x] != '1' && game->map_items[i - x] != 'E')
	{
		if (game->map_items[i - x] == 'C')
			game->collected++;
		game->map_items[i] = '0';
		game->map_items[i - x] = 'P';
		game->steps++;
		ft_printf("Moves: %d\n", game->steps);
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
	check_exit(game, game->map_items[i + x]);
	if (game->map_items[i + x] != '1' && game->map_items[i + x] != 'E')
	{
		if (game->map_items[i + x] == 'C')
			game->collected++;
		game->map_items[i] = '0';
		game->map_items[i + x] = 'P';
		game->steps++;
		ft_printf("Moves: %d\n", game->steps);
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
	check_exit(game, game->map_items[i + 1]);
	if (game->map_items[i + 1] != '1' && game->map_items[i + 1] != 'E')
	{
		if (game->map_items[i + 1] == 'C')
			game->collected++;
		game->map_items[i] = '0';
		game->map_items[i + 1] = 'P';
		game->steps++;
		ft_printf("Moves: %d\n", game->steps);
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
	check_exit(game, game->map_items[i - 1]);
	if (game->map_items[i - 1] != '1' && game->map_items[i - 1] != 'E')
	{
		if (game->map_items[i - 1] == 'C')
			game->collected++;
		game->map_items[i] = '0';
		game->map_items[i - 1] = 'P';
		game->steps++;
		ft_printf("Moves: %d\n", game->steps);
	}
}

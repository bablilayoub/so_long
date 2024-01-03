/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:20:39 by abablil           #+#    #+#             */
/*   Updated: 2024/01/03 10:25:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	spawn_enemy(t_data *game, int *i, int *temp, int *already_spawned)
{
	*already_spawned = 1;
	while (game->map_items[*i] && game->map_items[*i] != 'C')
		(*i)++;
	*temp = *i;
	while (game->map_items[*i] && game->map_items[*i] != '0')
		(*i)++;
	if (*i == *temp)
	{
		while (game->map_items[*i] && game->map_items[*i] != '0')
			(*i)--;
	}
	game->map_items[*i] = 'X';
}

void	handle_spawn_enemy(t_data *game, int *i, int *temp, int *a_s)
{
	if (!*a_s)
		spawn_enemy(game, i, temp, a_s);
}

void	handle_player_collisions(t_data *game, int i)
{
	if (game->map_items[i - 1] == 'P')
		game_over(game, i - 1);
	if (game->map_items[i + 1] == 'P')
		game_over(game, i + 1);
}

void	handle_move_enemy(t_data *game, int i, int *go_back)
{
	if (game->map_items[i + 1] == '0' && !*go_back)
		move_enemy_right(game, i);
	else if (game->map_items[i - 1] == '0')
	{
		*go_back = 1;
		move_enemy_left(game, i);
	}
	else if (game->map_items[i - game->width] == '0' && !*go_back)
	{
		*go_back = 1;
		move_enemy_up_and_down(game, i, i - game->width);
	}
	else if (game->map_items[i + game->width] == '0' && !*go_back)
	{
		*go_back = 1;
		move_enemy_up_and_down(game, i, i + game->width);
	}
	else
		*go_back = 0;
}

int	handle_enemy(t_data *game)
{
	static int	already_spawned = 0;
	static int	go_back = 0;
	static int	count = TIMEOUT;
	int			i;
	int			temp;

	count--;
	if (count != 0)
		return (0);
	else
		count = TIMEOUT;
	i = 0;
	temp = 0;
	handle_spawn_enemy(game, &i, &temp, &already_spawned);
	if (already_spawned)
	{
		while (game->map_items[i] != 'X')
			i++;
		handle_player_collisions(game, i);
		handle_move_enemy(game, i, &go_back);
	}
	render_map(game);
	return (0);
}

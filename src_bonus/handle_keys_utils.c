/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:14:21 by abablil           #+#    #+#             */
/*   Updated: 2023/12/28 10:14:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_and_enemy(t_data *game, char position)
{
	if (position == 'E' && game->collectables == game->collected)
	{
		game->game_over++;
		game->steps++;
		ft_printf("You Win !!\n");
	}
	if (position == 'X')
	{
		game->game_over++;
		game->steps++;
		ft_printf("I got you bro :) !!\n");
		close_game(game);
	}
}

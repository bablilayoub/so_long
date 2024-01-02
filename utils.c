/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:45:10 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 17:00:04 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_error(char *str, t_data *game)
{
	if (game->mlx && game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->map_items)
		free(game->map_items);
	if (game->temp)
		free(game->temp);
	if (game->map)
		free_2d(game->map);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

int	close_game(t_data *game)
{
	if (game->mlx && game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->map_items)
		free(game->map_items);
	if (game->temp)
		free(game->temp);
	if (game->map)
		free_2d(game->map);
	ft_printf("%s closed !", GAME_NAME);
	exit(EXIT_SUCCESS);
}

void	init_values(t_data *game)
{
	game->map_items = NULL;
	game->map = NULL;
	game->temp = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->exit_closed = NULL;
	game->item = NULL;
	game->player = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->player_top = NULL;
	game->space = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->width = 0;
	game->height = 0;
	game->players = 0;
	game->exits = 0;
	game->game_over = 0;
	game->steps = 0;
	game->collected = 0;
	game->collectables = 0;
}

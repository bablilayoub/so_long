/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:45:10 by abablil           #+#    #+#             */
/*   Updated: 2023/12/28 18:14:36 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_game(t_data *game)
{
	if (game->map_items)
		free(game->map_items);
	if (game->mlx)
		free(game->mlx);
}

void	send_error(char *str, t_data *game)
{
	free_game(game);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

int	close_game(t_data *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_game(game);
	ft_printf("%s closed !", GAME_NAME);
	exit(EXIT_SUCCESS);
}

void	init_values(t_data *game)
{
	game->map_items = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->exit_closed = NULL;
	game->item = NULL;
	game->player = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->player_top = NULL;
	game->enemy = NULL;
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

void	render_moves_and_collected(t_data *game)
{
	char	*value;
	char	*text;
	char	*temp;

	value = ft_itoa(game->steps);
	temp = ft_strdup("Moves : ");
	text = ft_strjoin(temp, value);
	mlx_string_put(game->mlx, game->mlx_win,
		10,
		game->height * ITEM_SIZE + 12, 0xFFFFFF, text);
	free(value);
	free(text);
	value = ft_itoa(game->collected);
	temp = ft_strdup("Collected : ");
	text = ft_strjoin(temp, value);
	mlx_string_put(game->mlx, game->mlx_win,
		game->width * ITEM_SIZE - 150,
		game->height * ITEM_SIZE + 12, 0xFFFFFF, text);
	free(value);
	free(text);
}
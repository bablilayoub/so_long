/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:47:57 by abablil           #+#    #+#             */
/*   Updated: 2023/12/30 09:30:56 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_teleport(t_data *game)
{
	int	h_w;

	h_w = ITEM_SIZE;
	game->door_enter = mlx_xpm_file_to_image(game->mlx,
			"../assets/door_enter.xpm", &h_w, &h_w);
	game->door_exit = mlx_xpm_file_to_image(game->mlx,
			"../assets/door_exit.xpm", &h_w, &h_w);
	if (!game->door_enter || !game->door_exit)
	{
		free(game->mlx_win);
		free(game->mlx);
		send_error("Missing textures!\n", game);
	}
}

void	spawn_portals(t_data *game)
{
	int	i;

	i = 0;
	while (game->map_items[i] && game->map_items[i] != 'P')
		i++;
	spawn_portal_enter(game, &i);
	i = 0;
	spawn_portal_exit(game, &i);
}

void	destroy_portals(t_data *game)
{
	int	i;

	i = 0;
	while (game->map_items[i] != 'N')
		i++;
	if (i)
		game->map_items[i] = '0';
	i = 0;
	while (game->map_items[i] != 'M')
		i++;
	if (i)
		game->map_items[i] = '0';
}

int	teleport_player(t_data *game, int i, int temp, int p)
{
	while (game->map_items[i] && game->map_items[i] != 'M')
		i++;
	while (game->map_items[i] && game->map_items[i] != '0')
		i++;
	if (i == game->width * game->height)
	{
		i--;
		while (game->map_items[i] && game->map_items[i] != '0')
			i--;
	}
	game->map_items[p] = '0';
	game->map_items[i] = 'P';
	i = 0;
	while (game->map_items[i] != 'M')
		i++;
	temp = 0;
	while (game->map_items[temp] != 'N')
		temp++;
	game->map_items[i] = 'N';
	game->map_items[temp] = 'M';
	return (1);
}

int	check_for_portals(t_data *game, char position)
{
	int	p;
	int	i;
	int	temp;

	i = 0;
	p = 0;
	temp = 0;
	while (game->map_items[p] != 'P')
		p++;
	if (position == 'N')
		return (teleport_player(game, i, temp, p));
	if (position == 'M')
		return (1);
	return (0);
}

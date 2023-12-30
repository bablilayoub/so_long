/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:04:26 by abablil           #+#    #+#             */
/*   Updated: 2023/12/30 09:26:50 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	spawn_portal_enter(t_data *game, int *i)
{
	while (game->map_items[*i] && game->map_items[*i] != '0')
		(*i)++;
	if (*i == game->width * game->height)
	{
		(*i)--;
		while (game->map_items[*i] && game->map_items[*i] != '0')
			(*i)--;
	}
	game->map_items[*i] = 'N';
}

void	spawn_portal_exit(t_data *game, int *i)
{
	while (game->map_items[*i] && game->map_items[*i] != 'E')
		(*i)++;
	while (game->map_items[*i] && game->map_items[*i] != '0')
		(*i)++;
	if (*i == game->width * game->height)
	{
		(*i)--;
		while (game->map_items[*i] && game->map_items[*i] != '0')
			(*i)--;
	}
	game->map_items[*i] = 'M';
}

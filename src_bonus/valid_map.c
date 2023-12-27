/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:27:35 by abablil           #+#    #+#             */
/*   Updated: 2023/12/26 23:59:15 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_item(char c)
{
	char *items = "01CEP\n";
	int i = 0;
	while (items[i])
	{
		if (items[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void check_walls(t_data *game)
{
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map = ft_split(game->map_items, '\n');
	while (map[i])
	{
		while (i == 0 && map[i][j] == '1')
			j++;
		if (i == 0 && j != game->width)
			send_error("First line of the map must contain only walls", game);
		if (map[i][0] != '1' || map[i][game->width - 1] != '1')
			send_error("Map lines must start and end with a wall", game);
		i++;
	}
	i--;
	j = 0;
	while (map[i][j] == '1')
		j++;
	if (j != game->width)
		send_error("Last line of the map must contain only walls", game);
}

void remove_new_lines(t_data *game)
{
	int i;
	int j;
	char *new_map;

	i = 0;
	j = 0;
	new_map = (char *)malloc(sizeof(char) * ft_strlen(game->map_items));
	if (!new_map)
		send_error("Faild to allocate new map", game);
	while (game->map_items[i])
	{
		if (game->map_items[i] == '\n')
			i++;
		if (game->map_items[i])
			new_map[j] = game->map_items[i];
		i++;
		j++;
	}
	free(game->map_items);
	game->map_items = new_map;
}

void check_map_size(t_data *game)
{
	int prev;
	int i;
	int current;

	prev = 0;
	i = 0;
	while (game->map_items[i])
	{
		current = 0;
		while (game->map_items[i] && game->map_items[i] != '\n')
		{
			current++;
			i++;
		}
		if (prev == 0)
			prev = current;
		if (prev != current)
			send_error("Map size is invalid", game);
		if (game->map_items[i] == '\n')
			i++;
	}
	game->width = current;
}

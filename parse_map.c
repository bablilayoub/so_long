/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:06:01 by abablil           #+#    #+#             */
/*   Updated: 2023/12/25 20:32:16 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *get_items(int fd, t_data *game)
{
	char *temp;
	char *result;

	result = ft_strdup("");
	if (!result)
		send_error("Faild to allocate result", game);
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp[0] != '\n')
			result = ft_strjoin(result, temp);
		else
		{
			free(temp);
			send_error("Invalid Map ! (Line starts with new line)", game);
		}
		temp = get_next_line(fd);
	}
	return (result);
}

void get_map_hight(t_data *game)
{
	int i = 0;

	while (game->map_items[i])
	{
		if (game->map_items[i] != '\n')
			game->height++;
		while (game->map_items[i] && game->map_items[i] != '\n')
			i++;
		if (game->map_items[i] == '\n')
			i++;
	}
}

void check_map_structure(t_data *game)
{
	get_map_hight(game);
	check_walls(game);
}

void check_map(t_data *game)
{
	int i;

	i = 0;
	while (game->map_items[i])
	{
		if (!valid_item(game->map_items[i]))
			send_error("Invalid map ! (Invalid item)", game);
		i++;
	}
	check_map_size(game);
	check_map_structure(game);
	remove_new_lines(game);
}

void parse_map(int fd, t_data *game)
{
	int i;

	i = 0;
	game->map_items = get_items(fd, game);
	check_map(game);
	while (game->map_items[i])
	{
		if (game->map_items[i] == 'C')
			game->collectables++;
		if (game->map_items[i] == 'P')
			game->players++;
		if (game->map_items[i] == 'E')
			game->exits++;
		i++;
	}
	if (game->players != 1)
		send_error("Invalid Map! (1 player is required)", game);
	if (game->exits != 1)
		send_error("Invalid Map! (1 exit is required)", game);
	if (game->collectables == 0)
		send_error("Invalid Map! (at least 1 collectable must be on the map)", game);
}

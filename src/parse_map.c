/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:06:01 by abablil           #+#    #+#             */
/*   Updated: 2024/01/01 15:51:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_items(int fd, t_data *game)
{
	char	*temp;
	char	*result;

	result = ft_strdup("");
	if (!result)
		send_error("Failed to allocate result.", game);
	temp = get_next_line(fd);
	while (temp)
	{
		game->height++;
		if (temp[0] != '\n')
			result = ft_strjoin(result, temp);
		else
		{
			free(temp);
			free(result);
			send_error("Invalid Map! Lines should not start with a new line",
				game);
		}
		free(temp);
		temp = get_next_line(fd);
	}
	return (result);
}

void	can_i_reach_items(char *map, int p, int x, int *found_exit)
{
	if (map[p + 1] == 'E' || map[p - 1] == 'E'
		|| map[p + x] == 'E' || map[p - x] == 'E')
		*found_exit = 1;
	if (map[p + x] == '0' || map[p + x] == 'C')
	{
		map[p + x] = 'P';
		can_i_reach_items(map, p + x, x, found_exit);
	}
	if (map[p - x] == '0' || map[p - x] == 'C')
	{
		map[p - x] = 'P';
		can_i_reach_items(map, p - x, x, found_exit);
	}
	if (map[p + 1] == '0' || map[p + 1] == 'C')
	{
		map[p + 1] = 'P';
		can_i_reach_items(map, p + 1, x, found_exit);
	}
	if (map[p - 1] == '0' || map[p - 1] == 'C')
	{
		map[p - 1] = 'P';
		can_i_reach_items(map, p - 1, x, found_exit);
	}
}

void	is_valid_map(t_data *game)
{
	int		found_exit;
	int		i;
	char	*map;

	found_exit = 0;
	i = 0;
	map = ft_strdup(game->map_items);
	if (!map)
		send_error("Failed to allocate a new map", game);
	while (map[i] != 'P')
		i++;
	can_i_reach_items(map, i, game->width, &found_exit);
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
		{
			free(map);
			send_error("Collectables must not be surrounded by walls.",
				game);
		}
		i++;
	}
	check_if_found_exit(game, found_exit, map);
}

void	check_map(t_data *game)
{
	int		i;

	i = 0;
	while (game->map_items[i])
	{
		if (!valid_item(game->map_items[i]))
			send_error("Invalid map! Found an invalid item", game);
		i++;
	}
	check_map_size(game);
	check_walls(game);
	remove_new_lines(game);
	is_valid_map(game);
}

void	parse_map(int fd, t_data *game)
{
	int	i;

	i = 0;
	game->map_items = get_items(fd, game);
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
		send_error("Invalid Map! (At least 1 collectable must be on the map)",
			game);
	check_map(game);
}

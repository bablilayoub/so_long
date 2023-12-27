/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:06:01 by abablil           #+#    #+#             */
/*   Updated: 2023/12/27 05:26:02 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_items(int fd, t_data *game)
{
	char	*temp;
	char	*result;

	result = ft_strdup("");
	if (!result)
		send_error("Faild to allocate result", game);
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
			send_error("Invalid Map ! (Line starts with new line)", game);
		}
		free(temp);
		temp = get_next_line(fd);
	}
	if (temp)
		free(temp);
	return (result);
}

void	check_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->map_items[i])
	{
		if (!valid_item(game->map_items[i]))
			send_error("Invalid map ! (Invalid item)", game);
		i++;
	}
	check_map_size(game);
	check_walls(game);
	is_valid_map(game);
	remove_new_lines(game);
}

void	parse_map(int fd, t_data *game)
{
	int	i;

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
		send_error("Invalid Map! (at least 1 collectable must be on the map)",
			game);
}

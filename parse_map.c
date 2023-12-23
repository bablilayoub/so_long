/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:06:01 by abablil           #+#    #+#             */
/*   Updated: 2023/12/23 22:09:20 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_sub_lines(char *s1, char *s2)
{
	char	*new;
	char	*tmp;

	if (s1 == NULL)
		return (ft_strtrim(s2, "\n"));
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}

void	ft_check_map(t_data *map)
{
	int	i;
	int	j;

	i = map->width;
	while (i > -1)
	{
		if (map->map_items[i] != '1')
		    send_error("Invalid Map!\n", map);
		i--;
	}
	i = map->width;
	j = ft_strlen(map->map_items);
	while (i > -1)
	{
		if (map->map_items[j - 1] != '1')
		    send_error("Invalid Map!\n", map);
		j--;
		i--;
	}
	if (map->width > 40 || map->height > 21)
		send_error("Map will not fit to window!\n", map);
}

int	check_sub_line(t_data *map, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		free(*line);
	    send_error("Invalid Map!\n", map);
	}
	return (1);
}

int	check_line(t_data *map, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = check_sub_line(map, line, 0);
	while ((*line)[i + 1] != '\n' && (*line)[i + 1])
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
			&& (*line)[i] != 'E' && (*line)[i] != 'P')
		{
			free(*line);
		    send_error("Invalid Map!\n", map);
		}
		i++;
	}
	i = i + check_sub_line(map, line, i);
	tmp = map->map_items;
	map->map_items = join_sub_lines(tmp, *line);
	free(tmp);
	free(*line);
	if (i != map->width && map->width != 0)
	    send_error("Invalid Map!\n", map);
	*line = get_next_line(fd);
	map->height++;
	return (i);
}

void	parse_map(int fd, t_data *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
	    send_error("Invalid Map!\n", game);
	while (line != NULL)
		game->width = check_line(game, &line, fd);
	close(fd);
	ft_check_map(game);
	i = 0;
	fd = 0;
	while (game->map_items[fd])
	{
		if (game->map_items[fd] == 'C')
			game->max_score++;
		if (game->map_items[fd] == 'P')
			game->players++;
		if (game->map_items[fd] == 'E')
			i++;
		fd++;
	}
	if ((game->width == game->height) || game->players != 1
		|| i == 0 || game->max_score == 0)
	    send_error("Invalid Map!\n", game);
}

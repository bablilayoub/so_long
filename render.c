/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:35:28 by abablil           #+#    #+#             */
/*   Updated: 2023/12/23 22:23:53 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_data *game)
{
	int	h_w;

	h_w = ITEM_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &h_w, &h_w);
	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &h_w, &h_w);
	game->item = mlx_xpm_file_to_image(game->mlx, "assets/item.xpm", &h_w, &h_w);
	game->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &h_w, &h_w);
	game->space = mlx_xpm_file_to_image(game->mlx, "assets/space.xpm", &h_w, &h_w);
	if (!game->wall || !game->exit || !game->item || !game->player || !game->space)
	{
		free(game->mlx_win);
		free(game->mlx);
		send_error("Missing textures!\n", game);
	}
}

void	render_map(t_data *map, int i)
{
	int		x;
	int		y;
	char	*s;

	y = -1;
	while (y++ < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_items[i] == '1')
				s = map->wall;
			if (map->map_items[i] == '0')
				s = map->space;
			if (map->map_items[i] == 'C')
				s = map->item;
			if (map->map_items[i] == 'P')
				s = map->player;
			if (map->map_items[i] == 'E')
				s = map->exit;
			mlx_put_image_to_window(map->mlx, map->mlx_win, s, x * ITEM_SIZE, y * ITEM_SIZE);
			i++;
			x++;
		}
	}
}

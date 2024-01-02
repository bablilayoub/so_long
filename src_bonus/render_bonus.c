/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:35:28 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 08:44:33 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_xpm(t_data *game, int *h_w)
{
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"../assets/wall.xpm", h_w, h_w);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"../assets/exit.xpm", h_w, h_w);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx,
			"../assets/exit_closed.xpm", h_w, h_w);
	game->item = mlx_xpm_file_to_image(game->mlx,
			"../assets/item.xpm", h_w, h_w);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"../assets/player.xpm", h_w, h_w);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_left.xpm", h_w, h_w);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_right.xpm", h_w, h_w);
	game->player_top = mlx_xpm_file_to_image(game->mlx,
			"../assets/player_top.xpm", h_w, h_w);
	game->space = mlx_xpm_file_to_image(game->mlx,
			"../assets/space.xpm", h_w, h_w);
}

void	render_enemy(t_data *game, int h_w)
{
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy.xpm", &h_w, &h_w);
	game->enemy_right_1 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_1.xpm", &h_w, &h_w);
	game->enemy_right_2 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_2.xpm", &h_w, &h_w);
	game->enemy_right_3 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_3.xpm", &h_w, &h_w);
	game->enemy_right_4 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_4.xpm", &h_w, &h_w);
	game->enemy_right_4 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_4.xpm", &h_w, &h_w);
	game->enemy_right_5 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_5.xpm", &h_w, &h_w);
	game->enemy_right_6 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_6.xpm", &h_w, &h_w);
	game->enemy_right_7 = mlx_xpm_file_to_image(game->mlx,
			"../assets/enemy_right_7.xpm", &h_w, &h_w);
}

void	render_image(t_data *game)
{
	int	h_w;

	h_w = ITEM_SIZE;
	init_xpm(game, &h_w);
	init_teleport(game);
	render_enemy(game, h_w);
	render_enemy_left(game, h_w);
	if (!game->wall || !game->exit || !game->item
		|| !game->player || !game->player_left || !game->enemy_left_1
		|| !game->player_right || !game->player_top || !game->space
		|| !game->exit_closed || !game->enemy_right_1 || !game->enemy
		|| !game->enemy_right_2 || !game->enemy_right_3 || !game->enemy_right_4
		|| !game->enemy_right_5 || !game->enemy_right_6 || !game->enemy_right_7
		|| !game->enemy_left_2 || !game->enemy_left_3 || !game->enemy_left_4
		|| !game->enemy_left_5 || !game->enemy_left_6 || !game->enemy_left_7)
		send_error("Textures are missing!\n", game);
}

char	*get_element(int *i, t_data *game)
{
	if (game->map_items[*i] == '1')
		return (game->wall);
	else if (game->map_items[*i] == '0')
		return (game->space);
	else if (game->map_items[*i] == 'C')
		return (game->item);
	else if (game->map_items[*i] == 'P')
		return (game->player);
	else if (game->map_items[*i] == 'X')
		return (game->enemy);
	else if (game->map_items[*i] == 'N')
		return (game->door_enter);
	else if (game->map_items[*i] == 'M')
		return (game->door_exit);
	else if (game->map_items[*i] == 'E'
		&& game->collectables != game->collected)
		return (game->exit_closed);
	else if (game->map_items[*i] == 'E'
		&& game->collectables == game->collected)
		return (game->exit);
	return (NULL);
}

void	render_map(t_data *game)
{
	int		x;
	int		y;
	int		i;
	void	*element;

	i = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width && game->map_items[i])
		{
			element = get_element(&i, game);
			if (element)
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, element, x * ITEM_SIZE, y * ITEM_SIZE);
			else
				send_error("Failed to get element", game);
			i++;
			x++;
		}
		y++;
	}
}

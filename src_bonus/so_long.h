/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:06:01 by abablil           #+#    #+#             */
/*   Updated: 2023/12/27 02:06:51 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

// Game name
# define GAME_NAME "Run Boy"

// Items size (pixels)
# define ITEM_SIZE 48

// Enemy moves timeout
# define TIMEOUT 1500

// Game struct
typedef struct s_data
{
	char	*map_items;
	void	*wall;
	void	*exit;
	void	*exit_closed;
	void	*item;
	void	*space;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_top;
	void	*enemy;
	void	*enemy_left;
	void	*enemy_right;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		players;
	int		exits;
	int		game_over;
	int		steps;
	int		collected;
	int		collectables;
}	t_data;

// Args handler
char	*args_handler(int total, char **args, t_data *game);

/// Utils
void	init_values(t_data *game);
void	send_error(char *str, t_data *game);
int		close_game(t_data *game);
void	render_moves(t_data *game);

// Init game
void	init_game(char *map_name, t_data *game);

// Parse map
void	parse_map(int fd, t_data *game);

// Render
void	render_image(t_data *game);
void	render_map(t_data *map);

// Valid map
int		valid_item(char c);
void	check_walls(t_data *game);
void	remove_new_lines(t_data *game);
void	check_map_size(t_data *game);

// Handle keys
void	handle_w_key(t_data *game);
void	handle_s_key(t_data *game);
void	handle_d_key(t_data *game);
void	handle_a_key(t_data *game);

// Enemy
int		handle_enemy(t_data *game);

// Enemy utils
void	move_enemy_left(t_data *game, int i);
void	move_enemy_right(t_data *game, int i);
void	move_enemy_up(t_data *game, int i);
void	move_enemy_down(t_data *game, int i);
void	handle_player_collision(t_data *game, int i);

#endif

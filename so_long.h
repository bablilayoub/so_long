#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <libc.h>
#include "libs/ft_printf/ft_printf.h"
#include "libs/libft/libft.h"
#include "libs/get_next_line/get_next_line_bonus.h"

#define GAME_NAME "Run Boy"
#define ITEM_SIZE 48

typedef struct s_data
{
	char *map_items;
	void *wall;
	void *exit;
	void *item;
	void *player;
	void *space;
	void *mlx;
	void *mlx_win;
	int width;
	int height;
	int players;
	int game_over;
	int steps;
	int score;
	int max_score;
} t_data;

// Args handler
char *args_handler(int total, char **args, t_data *game);

/// Utils
void	init_values(t_data *game);
void	send_error(char *str, t_data *game);
int		close_game(t_data *game);

// Init game
void	init_game(char *map_name, t_data *game);

// Parse map
void	parse_map(int fd, t_data *game);

// Render
void	render_image(t_data *game);
void	render_map(t_data *map, int i);

// Handle keys
void	handle_w_key(t_data *game);
void	handle_s_key(t_data *game);
void	handle_d_key(t_data *game);
void	handle_a_key(t_data *game);

#endif

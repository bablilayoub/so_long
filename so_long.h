#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <libc.h>
# include "libs/ft_printf/ft_printf.h"
# include "libs/libft/libft.h"

# define GAME_NAME "Run Boy"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
    char *map_name;
} t_data;

// Args handler
char    *args_handler(int total, char **args);

// Window sizes
int     get_walls(char type, char *path);

// Window Maker
void    window_maker(void *mlx, void *mlx_win, t_data *data);

#endif

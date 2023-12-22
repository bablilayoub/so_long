#include "so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(int total, char **args)
{
	void *mlx;
	void *mlx_win;
	t_data data;

	mlx = NULL;
	mlx_win = NULL;
	data.map_name = args_handler(total, args);
	window_maker(mlx, mlx_win, &data);
}
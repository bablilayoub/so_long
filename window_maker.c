/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:25:26 by abablil           #+#    #+#             */
/*   Updated: 2023/12/22 21:35:43 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    window_maker(void *mlx, void *mlx_win, t_data *data)
{
	int horizontal_len = get_walls('h', data->map_name) * 70;
	int vertical_len = get_walls('v', data->map_name) * 70;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, horizontal_len, vertical_len, GAME_NAME);
	data->img = mlx_new_image(mlx, horizontal_len, vertical_len);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
	mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:50:03 by abablil           #+#    #+#             */
/*   Updated: 2023/12/28 17:51:30 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int total, char **args)
{
	t_data	game;
	char	*map_name;

	init_values(&game);
	map_name = args_handler(total, args, &game);
	init_game(map_name, &game);
}
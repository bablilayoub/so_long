/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:50:03 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 17:25:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int total, char **args)
{
	t_data	game;
	char	*map_name;

	init_values(&game);
	map_name = args_handler(total, args, &game);
	if (!map_name)
		send_error("Failed to allocate map name", &game);
	init_game(map_name, &game);
}

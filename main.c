/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:50:03 by abablil           #+#    #+#             */
/*   Updated: 2023/12/23 17:30:28 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int total, char **args)
{
	t_data game;
	char *map_name;

	map_name = args_handler(total, args, &game);
	init_values(&game);
	init_game(map_name, &game);
}
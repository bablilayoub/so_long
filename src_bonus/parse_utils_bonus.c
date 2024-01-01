/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:19:00 by abablil           #+#    #+#             */
/*   Updated: 2024/01/01 16:08:10 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_if_found_exit(t_data *game, int found_exit, char *map)
{
	if (!found_exit)
	{
		free(map);
		send_error("Invalid Map: Exit must not be surrounded by walls",
			game);
	}
	free(map);
}

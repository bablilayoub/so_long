/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:08:53 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 11:50:18 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*args_handler(int total, char **args, t_data *game)
{
	if (total < 2)
		send_error("Please enter the map name, e.g., map1.ber or map2.ber.",
			game);
	if (total > 2)
		send_error("Too many arguments.", game);
	if (!ft_strnstr(args[1] + ft_strlen(args[1]) - 4, ".ber",
			ft_strlen(args[1])))
		send_error("Wrong map format, make sure to add .ber at the end.", game);
	return (ft_strtrim(args[1], " "));
}

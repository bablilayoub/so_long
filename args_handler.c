/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:08:53 by abablil           #+#    #+#             */
/*   Updated: 2023/12/22 21:23:44 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *args_handler(int total, char **args)
{
    if (total < 2)
	{
		ft_printf("Please enter map name ex : map1.ber, map2.ber");
		exit(EXIT_FAILURE);
	}
    if (total > 2)
	{
		ft_printf("Too may arguments");
		exit(EXIT_FAILURE);
	}
    if (!ft_strnstr(args[1], ".ber", ft_strlen(args[1])))
    {
        ft_printf("Wrong map fomart, make sure to add .ber at the end");
        exit(EXIT_FAILURE);
    }
    return (ft_strtrim(args[1], " "));
}
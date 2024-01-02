/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_string_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:17:47 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 19:24:43 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_moves(t_data *game)
{
	char	*value;
	char	*text;
	char	*temp;

	temp = ft_strdup("Moves : ");
	value = ft_itoa(game->steps);
	text = ft_strjoin(temp, value);
	if (!temp || !value || !text)
	{
		free(value);
		free(text);
		send_error("Failed to allocate memory for moves text", game);
	}
	mlx_string_put(game->mlx, game->mlx_win, 10,
		game->height * ITEM_SIZE + 12, 0xFFFFFF, text);
	free(value);
	free(text);
}

void	render_collected(t_data *game)
{
	char	*value;
	char	*text;
	char	*temp;

	temp = ft_strdup("Collected : ");
	value = ft_itoa(game->collected);
	text = ft_strjoin(temp, value);
	if (!temp || !value || !text)
	{
		free(value);
		free(text);
		send_error("Failed to allocate memory for collected text", game);
	}
	mlx_string_put(game->mlx, game->mlx_win, game->width * ITEM_SIZE - 150,
		game->height * ITEM_SIZE + 12, 0xFFFFFF, text);
	free(value);
	free(text);
}

void	render_moves_and_collected(t_data *game)
{
	render_moves(game);
	render_collected(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:23 by abablil           #+#    #+#             */
/*   Updated: 2023/12/25 21:33:21 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_custom(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	*free_array(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	*read_data(int fd, char *data)
{
	char	*temp;
	int		reading;

	reading = 1;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (reading != 0 && !ft_strchr_custom(data, '\n'))
	{
		reading = read(fd, temp, BUFFER_SIZE);
		if (reading == -1)
			return (temp = free_array(temp));
		if (reading == 0)
			break ;
		temp[reading] = '\0';
		data = ft_strjoin_custom(data, temp);
	}
	return (free(temp), data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	char		*temp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	temp = read_data(fd, data);
	if (!temp)
		return (data = free_array(data));
	data = temp;
	if (line_len(data) == 0)
		return (data = free_array(data));
	line = ft_substr_custom(data, 0, line_len(data), 0);
	if (!line)
		return (data = free_array(data));
	data = ft_substr_custom(data, line_len(data), ft_strlen_custom(data) - line_len(data), 1);
	if (!data)
		return (data = free_array(data));
	return (line);
}

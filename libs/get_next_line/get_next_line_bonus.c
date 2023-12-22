/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:23 by abablil           #+#    #+#             */
/*   Updated: 2023/12/05 14:03:41 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
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
	while (reading != 0 && !ft_strchr(data, '\n'))
	{
		reading = read(fd, temp, BUFFER_SIZE);
		if (reading == -1)
			return (temp = free_array(temp));
		if (reading == 0)
			break ;
		temp[reading] = '\0';
		data = ft_strjoin(data, temp);
	}
	return (free(temp), data);
}

char	*get_next_line(int fd)
{
	static char	*data[OPEN_MAX];
	char		*line;
	char		*temp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	temp = read_data(fd, data[fd]);
	if (!temp)
		return (data[fd] = free_array(data[fd]));
	data[fd] = temp;
	if (line_len(data[fd]) == 0)
		return (data[fd] = free_array(data[fd]));
	line = ft_substr(data[fd], 0, line_len(data[fd]), 0);
	if (!line)
		return (data[fd] = free_array(data[fd]));
	data[fd] = ft_substr(data[fd],
			line_len(data[fd]), ft_strlen(data[fd]) - line_len(data[fd]), 1);
	if (!data[fd])
		return (data[fd] = free_array(data[fd]));
	return (line);
}

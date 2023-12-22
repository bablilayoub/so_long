/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:25 by abablil           #+#    #+#             */
/*   Updated: 2023/12/04 15:47:25 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

char	*ft_substr(char *s, size_t start, size_t end, int free_data)
{
	size_t	i;
	size_t	str_len;
	size_t	substr_len;
	char	*substr;

	if (!s)
		return (NULL);
	i = -1;
	str_len = ft_strlen(s);
	if ((str_len - start) >= end)
		substr_len = end;
	else
		substr_len = str_len - start;
	if (start > str_len)
		substr_len = 0;
	substr = (char *)malloc(sizeof(char) * substr_len + 1);
	if (!substr)
		return (NULL);
	while (++i < substr_len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	if (free_data == 1)
		free(s);
	return (substr);
}

char	*ft_strdup(char *s1)
{
	size_t	str_len;
	char	*new_str;

	if (!s1)
		return (NULL);
	str_len = ft_strlen(s1);
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, str_len + 1);
	return (new_str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		total_length;
	char	*result;

	if (!str1)
		str1 = ft_strdup("");
	if (str1 == NULL || str2 == NULL)
		return (str1 = free_array(str1));
	total_length = ft_strlen(str1) + ft_strlen(str2) + 1;
	result = (char *)malloc(sizeof(char) * total_length);
	if (!result)
		return (str1 = free_array(str1));
	ft_strlcpy(result, str1, total_length);
	ft_strlcpy(result + ft_strlen(str1), str2, total_length);
	if (str1)
		free(str1);
	return (result);
}

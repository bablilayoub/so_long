/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:38:33 by abablil           #+#    #+#             */
/*   Updated: 2024/01/02 19:24:09 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		total_length;
	char	*result;

	if (!str1)
		str1 = ft_strdup("");
	if (!str1)
		return (NULL);
	if (!str2)
		return (NULL);
	total_length = ft_strlen(str1) + ft_strlen(str2) + 1;
	result = (char *)malloc(sizeof(char) * total_length);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str1, total_length);
	ft_strlcat(result, str2, total_length);
	free(str1);
	return (result);
}

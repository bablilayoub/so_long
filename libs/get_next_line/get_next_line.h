/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:27 by abablil           #+#    #+#             */
/*   Updated: 2023/12/27 01:19:33 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_custom(char *str1, char *str2);
char	*ft_substr_custom(char *s, size_t start, size_t end, int free_data);
char	*ft_strchr_custom(char *str, char c);
size_t	ft_strlen_custom(char *s);
int		line_len(char *str);
void	*free_array(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:17:12 by anarodr2          #+#    #+#             */
/*   Updated: 2023/05/29 12:39:54 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		if (!s1)
			return (0);
	}	
	if (!s1 || !s2)
		return (NULL);
	s3 = ft_calloc(sizeof(char), ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (ft_free(&s1));
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	ft_free(&s1);
	return (s3);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc(size * count);
	if (!result)
	{
		ft_free(&result);
		return (0);
	}
	while (i < (size * count))
	{
		result[i] = '\0';
		i++;
	}
	return ((void *)result);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

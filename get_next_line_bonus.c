/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:17:04 by anarodr2          #+#    #+#             */
/*   Updated: 2023/05/30 11:55:10 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *full_text)
{
	char	*line;
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (!full_text[i])
		return (NULL);
	while (full_text[i] && full_text[i] != '\n')
		i++;
	line = (char *)ft_calloc(sizeof(char), i + 1 + (full_text[i] == '\n'));
	if (!line)
		return (NULL);
	while (full_text[f] && full_text[f] != '\n')
	{
		line[f] = full_text[f];
		f++;
	}
	if (full_text[i] == '\n')
		line[f] = '\n';
	return (line);
}

char	*ft_rest_text(char *text)
{
	char	*rest;
	int		i;
	int		f;

	rest = NULL;
	i = 0;
	f = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
		return (ft_free(&text));
	rest = ft_calloc(sizeof(char), ft_strlen(text) - i + 1);
	if (!rest)
		return (ft_free(&text));
	i++;
	while (f < ((int)ft_strlen(text) - i))
	{
		rest[f] = text[i + f];
		f++;
	}
	rest[f] = '\0';
	ft_free(&text);
	return (rest);
}

void	*ft_free(char **text)
{
	free(*text);
	*text = NULL;
	return (NULL);
}

char	*ft_reader(int fd, char *text)
{
	int			num;
	char		*buffer;

	num = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&text));
	while (num > 0 && !ft_strchr(buffer, '\n'))
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num > 0)
		{
			buffer[num] = '\0';
			text = ft_strjoin(text, buffer);
			if (text == NULL)
				break ;
		}
	}
	ft_free(&buffer);
	if (num == -1)
		return (ft_free(&text));
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text_buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!ft_strchr(text_buffer[fd], '\n'))
		text_buffer[fd] = ft_reader(fd, text_buffer[fd]);
	if (!text_buffer[fd])
		return (NULL);
	line = ft_line(text_buffer[fd]);
	if (!line)
		return (ft_free(&text_buffer[fd]));
	text_buffer[fd] = ft_rest_text(text_buffer[fd]);
	return (line);
}

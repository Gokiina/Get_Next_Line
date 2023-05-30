/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodr2 <anarodr2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:17:24 by anarodr2          #+#    #+#             */
/*   Updated: 2023/05/30 11:37:13 by anarodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/* PRINCIPALES */
char	*get_next_line(int fd);
char	*ft_rest_text(char *text);
char	*ft_line(char *full_text);
void	*ft_free(char **text);
char	*ft_reader(int fd, char *text);

/* UTILS */
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);

#endif
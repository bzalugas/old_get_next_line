/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:41 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/24 17:22:53 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

int	find(char c, char *str, size_t start)
{
	int	i;

	if (!str || start > ft_strlen(str))
		return (-1);
	i = start;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

int	get_the_line(char **line, char **text, int last)
{
	int	end_line;

	if (last && **text == 0)
	{
		*line = ft_substr_free(*text, 0, 0);
		return (0);
	}
	end_line = find('\n', *text, 0);
	if (end_line == -1)
		end_line = ft_strlen(*text);
	*line = ft_substr(*text, 0, end_line);
	*text = ft_substr_free(*text, end_line + 1, ft_strlen(*text));
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*text = NULL;
	int			result;
	int			end_line;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (text)
	{
		end_line = find('\n', text, 0);
		if (end_line != -1)
			return (get_the_line(line, &text, 0));
	}
	result = read(fd, buff, BUFFER_SIZE);
	while (result > 0)
	{
		buff[result] = '\0';
		text = ft_strjoin_free(text, buff);
		end_line = find('\n', text, 0);
		if (end_line != -1 || result < BUFFER_SIZE)
			return (get_the_line(line, &text, 0));
		result = read(fd, buff, BUFFER_SIZE);
	}
	return (get_the_line(line, &text, 1));
}

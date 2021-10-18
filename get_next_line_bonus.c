/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:31:59 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/18 21:02:14 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_line(char **text, int end_line)
{
	char	*line;

	if (!*text || !**text)
	{
		if (*text)
		{
			free(*text);
			*text = NULL;
		}
		return (NULL);
	}
	if (end_line == -1)
	{
		line = ft_substr_free(*text, 0, ft_strlen(*text), 1);
		*text = NULL;
	}
	else
	{
		line = ft_substr_free(*text, 0, end_line + 1, 0);
		*text = ft_substr_free(*text, end_line + 1, ft_strlen(*text), 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*fds[MAX_FD];
	char		*buf;
	int			end_line;
	int			result;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	end_line = ft_find_char('\n', fds[fd]);
	if (end_line == -1)
		result = read(fd, buf, BUFFER_SIZE);
	while (end_line == -1 && result > 0)
	{
		buf[result] = '\0';
		fds[fd] = ft_strjoin_free(fds[fd], buf, 1, 0);
		end_line = ft_find_char('\n', fds[fd]);
		if (end_line == -1)
			result = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (get_the_line(&fds[fd], end_line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:41 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/23 15:39:16 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(char **text, int end_line)
{
	char	*line;

	if (!*text || !**text)
	{
		if (*text)
			free(*text);
		return (NULL);
	}
	if (end_line == -1)
		end_line = ft_strlen(*text);
	line = ft_substr_free(*text, 0, end_line + 1, 0);
	*text = ft_substr_free(*text, end_line + 1, ft_strlen(*text), 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*text = NULL;
	int			result;
	int			end_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (NULL);
	if (text)
	{
		end_line = ft_find_char('\n', text, 0);
		if (end_line != -1)
			return (get_the_line(&text, end_line));
	}
	result = read(fd, buff, BUFFER_SIZE);
	while (result > 0)
	{
		buff[result] = '\0';
		text = ft_strjoin_free(text, buff, 1);
		end_line = ft_find_char('\n', text, 0);
		if (end_line != -1 || result < BUFFER_SIZE) //verifier condition en fct
													//du cpt attendu
			return (get_the_line(&text, end_line));
		result = read(fd, buff, BUFFER_SIZE);
	}
	return (get_the_line(&text, -1));
}

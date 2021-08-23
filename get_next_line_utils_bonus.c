/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:18 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/22 22:59:05 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int			ft_find_char(char c, char *str)
{
	int i;

	i = -1;
	while (str && str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

/*
** Search by fd for an existent gnlfile, if there isn't create a new one &
** add it to the linked chain
*/
t_gnlfile	*get_gnlfile(t_gnlfile **first, int fd)
{
	t_gnlfile   *tmp;
	t_gnlfile   *new;

	if (!first || fd < 0)
		return (NULL);
	tmp = *first;
	if (tmp && tmp->fd == fd)
		return (tmp);
	while (tmp && tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_gnlfile));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->text = NULL;
	new->next = NULL;
	if (!*first)
		*first = new;
	else
		tmp->next = new;
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

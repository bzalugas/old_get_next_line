/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:18 by bzalugas          #+#    #+#             */
/*   Updated: 2021/09/29 17:59:15 by bzalugas         ###   ########.fr       */
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

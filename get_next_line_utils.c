/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:23 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/20 19:15:43 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
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

char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;
	int		i;

	if (!s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (!new)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(new, s1, s1_len + 1);
		i = -1;
		while (s2[++i])
			new[s1_len + i] = s2[i];
		new[s1_len + i] = '\0';
	}
	else
		ft_strlcpy(new, s2, s2_len + 1);
	free(s1);
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_strlcpy(new, "\0", 1);
	else
		ft_strlcpy(new, &s[start], len + 1);
	return (new);
}

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_strlcpy(new, "\0", 1);
	else
		ft_strlcpy(new, &s[start], len + 1);
	free(s);
	return (new);
}

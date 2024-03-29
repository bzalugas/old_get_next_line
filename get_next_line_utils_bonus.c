/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:18 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/18 21:05:44 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_find_char(char c, char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	char	*new;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc(sizeof(char) * len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		new[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		new[len1 + i] = s2[i];
	if (i < 0)
		i = 0;
	new[len1 + i] = '\0';
	if (free_s1 && s1)
		free(s1);
	if (free_s2 && s2)
		free(s2);
	return (new);
}

char	*ft_substr_free(char *s, unsigned int start, size_t len, int free_s)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			new[i] = s[start + i];
			i++;
		}
	}
	new[i] = '\0';
	if (free_s && s)
		free(s);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:46:23 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/18 12:48:01 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

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


int		main(int argc, char **argv)
{
	char	**files;
	int		*fd;
	char	*line;
	int		i;
	int		j;
	int		result;

	files = malloc(sizeof(char *) * argc - 1);
	fd = malloc(sizeof(int) * argc - 1);
	i = -1;
	while (++i < argc - 1)
	{
		files[i] = malloc(sizeof(char) * ft_strlen(argv[i + 1]) + 1);
		ft_strlcpy(files[i], argv[i + 1], ft_strlen(argv[i + 1]) + 1);
		fd[i] = open(files[i], O_RDONLY);
		if (fd[i] < 0)
			return (-1);
	}
	i = -1;
	printf("\n\n");
	result = 1;
	while (result)
	{
		j = 0;
		result = 0;
		while (files[j])
		{
			if ((line = get_next_line(fd[j])))
			{
				result = 1;
				printf("%s", line);
				free(line);
				line = NULL;
			}
			j++;
		}
	}
	i = -1;
	while (++i < argc - 1)
	{
		close(fd[i]);
		free(files[i]);
	}
	free(fd);
	free(files);
	return (0);
}

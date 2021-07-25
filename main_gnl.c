/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:23:12 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/25 17:28:35 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/errno.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*name;
	int		fd;
	char	*line = NULL;
	int		result;

	if (argc == 1)
		fd = 0;
	else
	{
		name = argv[1];
		fd = open(name, O_RDONLY);
		if (fd < 0)
			return (-1);
//		printf("contenu de %s : \n\n", name);
	}
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
        free(line);
        line = NULL;
	}
	if (line)
		free(line);
	close(fd);
}

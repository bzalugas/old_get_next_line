/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:23:12 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/10 20:30:12 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/errno.h>
#include "get_next_line.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	char	*name;
	int		fd;
	char	*line = NULL;

	(void)argc;
	if (argv[1][0] == '0')
		fd = 0;
	else
	{
		name = argv[1];
		fd = open(name, O_RDONLY);
		if (fd < 0)
			return (-1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

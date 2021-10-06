/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:31:59 by bzalugas          #+#    #+#             */
/*   Updated: 2021/09/29 19:36:22 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
    static char *fds[MAX_FD];
    char        *buf;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !buf)
        return (NULL);
    if (fds[fd] && )

}

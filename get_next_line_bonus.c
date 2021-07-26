/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:31:59 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/26 13:30:46 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int get_next_line(int fd, char **line)
{
    static t_file   *files;
    char            buf[BUFFER_SIZE + 1];
    int             result;

    if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, &buf, 0)) == -1)
        return (-1);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:31:59 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/23 13:55:20 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int get_the_line(char **text, char **line, int end_line)
{

}

int get_next_line(int fd, char **line)
{
    static t_gnlfile    *files = NULL;
    t_gnlfile           *file;
    char                buff[BUFFER_SIZE + 1];
    int                 end_line;

    if (fd < 0 || !line || read(fd, buff, 0) < 0)
        return (-1);
    file = get_gnlfile(&files, fd);
    if (file->text)
    {
        end_line = ft_find_char('\n', file->text);
        if (end_line != -1)

    }
}

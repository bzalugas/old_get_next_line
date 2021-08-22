/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:31:59 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/03 10:54:00 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

//int get_the_line(char **text, char **line, int end_line)
int get_the_line(t_file *lst, t_file *file, char **line, int end_line)
{
    if (!file->text || !*file->text)
    {
        *line = ft_substr_free(file->text, 0, 1, 1);
        if (file)
            delete_file(&lst, &file);
        printf("%s, file deleted : %p\n", __FUNCTION__, file);
        return (0);
    }
    if (end_line == -1)
        end_line = ft_strlen(file->text);
    *line = ft_substr_free(file->text, 0, end_line, 0);
    file->text = ft_substr_free(file->text, end_line + 1, ft_strlen(file->text), 1);
    if (!*line || !file->text)
        return (-1);
    return (1);
}

int get_next_line(int fd, char **line)
{
    static t_file   *lst = NULL;
    t_file          *file;
    char            buf[BUFFER_SIZE + 1];
    int             result;
    int             end_line;

    if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, &buf, 0) == -1)
        return (-1);
    file = find_or_create_file(fd, &lst);
    if (file->text)
    {
        end_line = find('\n', file->text);
        if (end_line != -1)
            return (get_the_line(NULL, file, line, end_line));
    }
    result = read(fd, &buf, BUFFER_SIZE);
    while(result > 0)
    {
        buf[result] = '\0';
        file->text = ft_strjoin_free(file->text, buf);
        end_line = find('\n', file->text);
        if (end_line != -1)
            return (get_the_line(NULL, file, line, end_line));
        result = read(fd, &buf, BUFFER_SIZE);
    }
    return (get_the_line(lst, file, line, -1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:41 by bzalugas          #+#    #+#             */
/*   Updated: 2021/06/15 18:17:38 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

int     find(char c, char *str, size_t start)
{
    int i;

    if (!str || start > ft_strlen(str))
        return -1;
    i = start;
    while (str[i] && str[i] != c)
        i++;
    if (!str[i])
        return -1;
    return i;
}

char    *get_the_line_and_cut_text(char **text, int end_line)
{
    char *line;

    if (end_line == -1 && (end_line = find('\n', *text, 0)) == -1)
        end_line = ft_strlen(*text);
    line = ft_substr(*text, 0, end_line);
    *text = ft_substr(*text, end_line + 1, ft_strlen(*text));
    return (line);
}

int     get_next_line(int fd, char **line)
{
    //char        buff[BUFFER_SIZE + 1];
    char        *buff;
    static char *text = NULL;
    static int  result = BUFFER_SIZE;
    int         end_line;

    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buff == NULL || fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
        return (-1);
    end_line = -1;
    while ((result != 0 || result == BUFFER_SIZE) && end_line < 0)
    {
        result = read(fd, buff, BUFFER_SIZE);
        buff[result] = '\0';
        if (text == NULL)
            text = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (text == NULL)
            return (-1);
        text = ft_strjoin(text, buff);
        end_line = find('\n', text, 0);
    }
    *line = get_the_line_and_cut_text(&text, end_line);
    free(buff);
    if (text && text[0] == '\0' && result < BUFFER_SIZE)
        return (0);
    return (1);
}

#include <fcntl.h>


int main()
{
    int fd = open("./test2.txt", O_RDONLY);
    char *line;
    if (!(line = malloc(sizeof(char) * BUFFER_SIZE)))
        exit(0);
    int result = 1;
    while (result > 0)
    {
        result = get_next_line(fd, &line);
        printf("next line : %s\n", line);
    }
    free(line);
    close(fd);
}

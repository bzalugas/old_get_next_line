/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:41 by bzalugas          #+#    #+#             */
/*   Updated: 2021/06/03 20:11:02 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

int find(char c, char *str, size_t start)
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

int     get_next_line(int fd, char **line)
{
    char        buff[BUFFER_SIZE + 1];
    static char *text = NULL;
    int         result;

    if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
        return (-1);
    result = read(fd, buff, BUFFER_SIZE);
    buff[BUFFER_SIZE] = '\0';
    text = ft_strjoin(text, buff);
    return 0;
}

#include <fcntl.h>


int main()
{
    int fd = open("./test2.txt", O_RDONLY);
    char *line = malloc(sizeof(char) * 50);
    int result = get_next_line(fd, &line);
    printf("%d\n", result);
    result = get_next_line(fd, &line);
    printf("%d\n", result);
    close(fd);
    free(line);
}

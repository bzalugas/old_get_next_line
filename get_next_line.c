/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:41 by bzalugas          #+#    #+#             */
/*   Updated: 2021/06/15 16:04:55 by bzalugas         ###   ########.fr       */
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

    line = ft_substr(*text, 0, end_line + 1);
    *text = ft_substr(*text, end_line + 1, ft_strlen(*text));
    return (line);
}

int     get_next_line(int fd, char **line)
{
    char        buff[BUFFER_SIZE + 1];
    static char *text = NULL;
    int         result;
    int         end_line;

    if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
        return (-1);
    end_line = -1;
    result = BUFFER_SIZE;
    //printf("avant while, voici mon texte : %s\n", text);
    while (result == BUFFER_SIZE && end_line < 0)
    {
        result = read(fd, buff, BUFFER_SIZE);
        //printf("dans le while, result : %d\n", result);
        buff[result] = '\0';
        //printf("dans le while, voici mon buff : %s\n", buff);
        if (text == NULL)
            text = malloc(sizeof(char) * BUFFER_SIZE + 1);
        text = ft_strjoin(text, buff);
        if (result == BUFFER_SIZE)
            end_line = find('\n', text, 0);
        else
            end_line = ft_strlen(text);
        //printf("fin de ligne : %d\n", end_line);
    }
    //printf("sorti du while, voici mon texte : %s", text);
    *line = get_the_line_and_cut_text(&text, end_line);
    //text = ft_substr(text, end_line + 1, ft_strlen(text));
    //printf("texte apres modif : %s\n", text);
    if (result < BUFFER_SIZE)
        return (0);
    return (1);
}

#include <fcntl.h>


int main()
{
    int fd = open("./test2.txt", O_RDONLY);
    char *line;
    if (!(line = malloc(sizeof(char) * 50)))
        exit(0);
    int result;
    int prev = 1;
    for(int i = 0; i < 10; i++)
    {
        result = get_next_line(fd, &line);

        //printf("%d\n", result);
        if (result >= 0 && prev != 0)
            printf("next line : %s", line);
        if (result == 0 && prev == 1)
            prev = 0;
    }
    close(fd);
    free(line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:46:23 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/03 10:46:29 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int     fd[10];
    char    *line1 = NULL;
    char    *line2 = NULL;
    int     result;
    int     i = -1;

/*    if (argc == 1)
        fd[0] = 0;
    else
        while (argv[++i + 1])
            fd[i] = open(argv[i + 1], O_RDONLY);
    if (fd[0] < 0)
        return (-1);
    i = -1;
    while (fd[++i])
    {
        printf("contenu de %s : \n\n", argv[i + 1]);
        while ((result = get_next_line(fd[i], &line)) > 0)
        {
            printf("%s\n", line);
            free(line);
            line = NULL;
        }
    }*/
    fd[0] = open("test2.txt", O_RDONLY);
    fd[1] = open("test.txt", O_RDONLY);
    while (get_next_line(fd[0], &line1) && get_next_line(fd[1], &line2))
    {
        printf("%s\n%s\n", line1, line2);
        free(line1);
        free(line2);
        line1 = NULL;
        line2 = NULL;
    }
    while (get_next_line(fd[0], &line1))
    {
        printf("%s\n", line1);
        free(line1);
        line1 = NULL;
    }
    while (get_next_line(fd[1], &line2))
    {
        printf("%s\n", line2);
        free(line2);
        line2 = NULL;
    }
    if (line1)
        free(line1);
    if (line2)
        free(line2);
    i = -1;
    while (fd[++i])
        close(fd[i]);
    return 0;
}

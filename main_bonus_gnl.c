/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:46:23 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/26 13:16:37 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *name1 = argv[1];
    char *name2 = argv[2];
    char buff1[11];
    char buff2[11];
    int fd1 = open(name1, O_RDONLY);
    int fd2 = open(name2, O_RDONLY);
    int result;

    (void)argc;

    result = read(fd1, &buff1, sizeof(buff1) - 1);
    buff1[result] = '\0';
    printf("read1 :\n%s\n", buff1);

    result = read(fd2, &buff2, sizeof(buff2) - 1);
    buff2[result] = '\0';
    printf("read2 :\n%s\n", buff2);

    result = read(fd1, &buff1, sizeof(buff1) - 1);
    buff1[result] = '\0';
    printf("read1 :\n%s\n", buff1);
}

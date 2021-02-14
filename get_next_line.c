/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:38:04 by bzalugas          #+#    #+#             */
/*   Updated: 2021/02/14 19:21:17 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

int	get_next_line(int fd, char **line)
{
    if (!BUFFER_SIZE)
        return (0);

}

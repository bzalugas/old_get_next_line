/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:45 by bzalugas          #+#    #+#             */
/*   Updated: 2021/09/29 19:13:49 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define MAX_FD 65536

#include <stdio.h> //to remove

size_t		ft_strlen(const char *s);
int			ft_find_char(char c, char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif

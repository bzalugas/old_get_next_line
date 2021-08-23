/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:45 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/23 13:59:36 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

#include <stdio.h>

typedef struct		s_gnlfile
{
	int					fd;
	char				*text;
	struct s_gnlfile	*next;
}					t_gnlfile;

size_t		ft_strlen(const char *s);
int			ft_find_char(char c, char *str);
t_gnlfile	*get_gnlfile(t_gnlfile **first, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif

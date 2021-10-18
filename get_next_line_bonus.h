/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:45 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/13 18:00:46 by bzalugas         ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
int		ft_find_char(char c, char *str);
char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2);
char	*ft_substr_free(char *s, unsigned int start, size_t len, int free_s);
char	*get_next_line(int fd);

#endif

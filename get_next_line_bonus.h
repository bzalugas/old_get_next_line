/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:45 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/03 10:52:53 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_file
{
	int				fd;
	char			*text;
	struct s_file	*next;
}					t_file;

int		find(char c, const char *str);
t_file	*find_or_create_file(int fd, t_file **lst);
size_t	ft_strlen(char const *str);
char	*ft_strjoin_free(char *s1, const char *s2);
char	*ft_substr_free(char *s, unsigned int start, size_t len, int to_free);
void    delete_file(t_file **lst, t_file **file);
//int		get_the_line(char **text, char **line, int end_line);
int get_the_line(t_file *lst, t_file *file, char **line, int end_line);
int		get_next_line(int fd, char **line);

#endif // GET_NEXT_LINE_BONUS_H

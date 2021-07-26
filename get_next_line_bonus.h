/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:45 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/26 13:26:37 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#include <unistd.h>

typedef struct		s_file
{
	int				fd;
	char			*text;
	struct s_file	*next;
}					t_file;

#endif // GET_NEXT_LINE_BONUS_H

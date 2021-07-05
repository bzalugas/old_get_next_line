/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:35:13 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/05 14:36:34 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAKS_TESTER_H_
# define LEAKS_TESTER_H_
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void            *content;
	struct s_list   *next;
} t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int     check_delete(t_list *lst, void *p);
void    *my_malloc(size_t size, const char *file, int line, const char *function);
void    my_free(void *p, const char *file, int line, const char *function);



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:33:17 by bzalugas          #+#    #+#             */
/*   Updated: 2021/06/18 13:50:44 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leaks_tester.h"

t_list *liste = NULL;

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst)
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
	else
		*alst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (del || *lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}

int     check_delete(t_list *lst, void *p)
{
	t_list *prev;
	t_list *tmp;
	int stop = 0;

	prev = lst;
	tmp = lst;
	while (tmp && !stop)
	{
		if (ft_memcmp(tmp->content, p, sizeof(p)) == 0)
		{
			if (ft_memcmp(prev, tmp, sizeof(lst)) == 0)
				liste = tmp->next;
			else
				prev->next = tmp->next;
			stop = 1;
			free(tmp);
		}
		if (!stop)
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
	if (stop)
		return 0;
	return 1;
}

void *my_malloc(size_t size, const char *file, int line, const char *function)
{
	void *p = malloc(size);
	if (!p)
		return NULL;
	printf("Malloc : %s, line %d, function %s : %p[%lu]\n", file, line, function, p, size);
	t_list *el = ft_lstnew(p);
	ft_lstadd_back(&liste, el);
	return p;
}

void my_free(void *p, const char *file, int line, const char *function)
{
	printf("Free : %s, line %d, function %s : %p[%lu]\n", file, line, function, p, sizeof(p));
	if (check_delete(liste, p) == 0)
		free(p);
}

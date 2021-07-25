/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:33:17 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/25 12:15:47 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEAKS_MACROS
#include "leaks_tester.h"
#include <fcntl.h>
#include "get_next_line.h"

t_list *g_liste = NULL;

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
				g_liste = tmp->next;
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
int nb_malloc = 0;
int nb_free = 0;
void *my_malloc(size_t size, const char *file, int line, const char *function)
{
	void *p = malloc(size);
	if (!p)
		return NULL;
	printf("Malloc : %s, line %d, function %s : %p[%lu]\n", file, line, function, p, size);
	t_list *el = ft_lstnew(p);
	ft_lstadd_back(&g_liste, el);
	nb_malloc++;
	return p;
}

void my_free(void *p, const char *file, int line, const char *function)
{
	printf("Free : %s, line %d, function %s : %p[%lu]\n", file, line, function, p, sizeof(p));
	nb_free++;
	check_delete(g_liste, p);
	free(p);
}

#define malloc(X) my_malloc(X, __FILE__, __LINE__, __FUNCTION__)
#define free(P) my_free(P, __FILE__, __LINE__, __FUNCTION__)

void afficher(void *content)
{
    printf("%p[%lu]\n", content, sizeof(content));
}

void delete(void *content)
{
    content = NULL;
}
int main(int argc, char **argv)
{
    char *name = argv[1];
    int fd = open(name, O_RDONLY);
    char *line;

    (void)argc;
    printf("Contenu de %s : \n\n", name);
	if (!fd)
		return 1;
	while (get_next_line(fd, &line))
    {
        printf("next line : %s\n", line);
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    if (line)
        free(line);
    close(fd);
    printf("nb malloc : %d\n", nb_malloc);
    printf("nb free : %d\n", nb_free);
    printf("adresses non liberees : \n");
    void (*aff)(void *);
    aff = &afficher;
    ft_lstiter(g_liste, aff);
    void (*del)(void *);
    del = &delete;
    ft_lstclear(&g_liste, del);
}

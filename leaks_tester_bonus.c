/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_tester_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:43:20 by bzalugas          #+#    #+#             */
/*   Updated: 2021/10/18 20:33:36 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEAKS_MACROS
#include "leaks_tester.h"
#include <fcntl.h>
#include "get_next_line_bonus.h"

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

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
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
			tmp = NULL;
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
	(void)file;
	(void)line;
	(void)function;
	printf("Malloc : %s, line %d, function %s : %p[%lu]\n", file, line, function, p, size);
	t_list *el = ft_lstnew(p);
	ft_lstadd_back(&g_liste, el);
	nb_malloc++;
	return p;
}

void my_free(void *p, const char *file, int line, const char *function)
{
	(void)file;
	(void)line;
	(void)function;
	printf("Free : %s, line %d, function %s : %p[%lu]\n", file, line, function, p, sizeof(p));
	if (check_delete(g_liste, p) == 0)
	{
		free(p);
		nb_free++;
	}
	else
		printf("\nfree error for %p\n", p);
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
	char	**files;
	int		*fd;
	char	*line;
	int		i;
	int		j;
	int		result;
	int		nb_files;

	nb_files = argc - 1;
	files = malloc(sizeof(char *) * nb_files);
	fd = malloc(sizeof(int) * nb_files);
	i = -1;
	while (++i < nb_files)
	{
		files[i] = malloc(sizeof(char) * ft_strlen(argv[i + 1]) + 1);
		ft_strlcpy(files[i], argv[i + 1], ft_strlen(argv[i + 1]) + 1);
		fd[i] = open(files[i], O_RDONLY);
		if (fd[i] < 0)
			return (-1);
	}
	printf("\n\n");
	i = -1;
	result = 1;
	while (result)
	{
		j = 0;
		result = 0;
		while (j < nb_files)
		{
			printf("next line of fd[%d]\n", fd[j]);
			if ((line = get_next_line(fd[j])))
			{
				result = 1;
				printf("line : %s\n", line);
				free(line);
				line = NULL;
			}
			j++;
		}
	}
	i = -1;
	while (++i < argc - 1)
	{
		close(fd[i]);
		fd[i] = -1;
		free(files[i]);
		files[i] = NULL;
	}
	free(fd);
	fd = NULL;
	free(files);
	files = NULL;
	printf("\n\n");
	printf( (nb_malloc == nb_free ? "No leaks, Bravo !\n" : "leak(s) detecte(s).\
 Decommenter les lignes en commentaire d'infos\n") );
    printf("nb malloc : %d\n", nb_malloc);
    printf("nb free : %d\n", nb_free);
    printf("adresses non liberees : \n");
    void (*aff)(void *);
    aff = &afficher;
    ft_lstiter(g_liste, aff);
    void (*del)(void *);
    del = &delete;
    ft_lstclear(&g_liste, del);
	return (0);
}

/* int main(void) */
/* { */
/* 	int fd[4]; */
/* 	char *line; */
/* 	fd[0] = open("textes/testers/41_with_nl", O_RDONLY); */
/* 	fd[1] = open("textes/testers/42_with_nl", O_RDONLY); */
/* 	fd[2] = open("textes/testers/43_with_nl", O_RDONLY); */
/* 	fd[3] = open("textes/testers/nl", O_RDONLY); */

/* 	line = get_next_line(1000); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[0]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(1001); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[1]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(1002); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[2]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(1003); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[0]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[1]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[2]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[3]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */
/* 	line = get_next_line(fd[3]); */
/* 	printf("%s", line); */
/* 	if (line) */
/* 	{ */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	printf("\n\n"); */

/* 	printf("nb malloc : %d\n", nb_malloc); */
/*     printf("nb free : %d\n", nb_free); */
/*     printf("adresses non liberees : \n"); */
/*     void (*aff)(void *); */
/*     aff = &afficher; */
/*     ft_lstiter(g_liste, aff); */
/*     void (*del)(void *); */
/*     del = &delete; */
/*     ft_lstclear(&g_liste, del); */
/* 	return (0); */
/* } */

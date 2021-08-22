/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:32:18 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/03 13:30:22 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int find(char c, const char *str)
{
    int i;

    i = -1;
    while (str && str[++i])
        if (str[i] == c)
            return (i);
    return (-1);
}

/*t_file *find_file(int fd, t_file *files)
{
    t_file *tmp;

    tmp = files;
    while(tmp && tmp->fd != fd && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp && tmp->fd == fd)
        return (tmp);
    return (NULL);
}*/

/*t_file  *file_new(int fd)
{
    t_file  *new;

    new = malloc(sizeof(t_file));
    if (!new)
        return (NULL);
    new->fd = fd;
    new->text = NULL;
    new->next = NULL;
    return (new);
}

void    file_add_back(t_file **first, t_file *new)
{
    t_file  *tmp;

    if (*first)
    {
        tmp = *first;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    else
        *first = new;
}*/

t_file  *find_or_create_file(int fd, t_file **lst)
{
    t_file  *file;
    t_file  *tmp;

    file = *lst;
    while (file && file->fd != fd)
        file = file->next;
    if (file)
        printf("found file : %p\nfd : %d\ntext : %s\nnext : %p\n",
            file, file->fd, file->text, file->next);
    if (!file)
    {
        file = malloc(sizeof(t_file));
        if (!file)
            return (NULL);
        file->fd = fd;
        file->text = NULL;
        file->next = NULL;
        if (*lst)
        {
            tmp = *lst;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = file;
        }
        else
            *lst = file;
        printf("created file : %p\nfd : %d\ntext : %s\nnext : %p\n",
               file, file->fd, file->text, file->next);
    }
    return (file);
}

void    delete_file(t_file **lst, t_file **file)
{
    t_file  *tmp;

    if (*file == *lst)
    {
        printf("file = %p\n*lst = %p\n", *file, *lst);
        *lst = (*lst)->next;
        printf("file = %p\n*lst = %p\n", *file, *lst);
    }
    else
    {
        tmp = *lst;
        while (tmp->next != *file)
            tmp = tmp->next;
        tmp->next = (*file)->next;
    }
    (*file)->fd = 0;
    (*file)->text = NULL;
    (*file)->next = NULL;
    free(*file);
    *file = NULL;
}

size_t  ft_strlen(char const *str)
{
    size_t  i;

    i = 0;
    if (str)
        while (str[i])
            i++;
    return (i);
}

char    *ft_strjoin_free(char *s1, const char *s2)
{
    size_t  len1;
    size_t  len2;
    int     i;
    char    *new;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if (!s2)
        return (NULL);
    new = malloc(sizeof(char) * len1 + len2 + 1);
    if (!new)
        return (NULL);
    i = -1;
    while (s1 && s1[++i])
        new[i] = s1[i];
    i = -1;
    while (s2[++i])
        new[len1 + i] = s2[i];
    new[len1 + len2] = '\0';
    free(s1);
    return (new);
}

char    *ft_substr_free(char *s, unsigned int start, size_t len, int to_free)
{
    char    *new;
    int     i;

    if (!s)
        return (NULL);
    new = malloc(sizeof(char) * len + 1);
    if (!new)
        return (NULL);
    i = -1;
    if (start >= ft_strlen(s))
        i = 0;
    else
        while (s[start + ++i] && i < (int)len)
            new[i] = s[start + i];
    new[i] = '\0';
    if (to_free)
        free(s);
    return (new);
}

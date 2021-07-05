/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:57:41 by bzalugas          #+#    #+#             */
/*   Updated: 2021/07/05 15:41:21 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "leaks_tester.h"
//#include "leaks_tester.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

extern t_list *liste;
extern int nb_malloc;
extern int nb_free;


int     find(char c, char *str, size_t start)
{
    int i;

    if (!str || start > ft_strlen(str))
        return -1;
    i = start;
    while (str[i] && str[i] != c)
        i++;
    if (!str[i])
        return -1;
    return i;
}

int     get_the_line(char **line, char **text, int end_line)
{

/*    if (end_line == -1 && (end_line = find('\n', *text, 0)) == -1)
        end_line = ft_strlen(*text);*/
//    printf("end line : %d\n", end_line);
//    printf("len : %lu\n", ft_strlen(*text));
    if (end_line == -1)
    {
        *line = ft_substr(*text, 0, ft_strlen(*text));
        free(*text);
        return (0);
    }
    *line = ft_substr(*text, 0, end_line);
    *text = ft_substr_free(*text, end_line + 1, ft_strlen(*text));
    return (1);
}

int     get_next_line(int fd, char **line)
{
    char        buff[BUFFER_SIZE + 1];
    static char *text = NULL;
    int         result;
    int         end_line;

    if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
        return (-1);
    if (text && (end_line = find('\n', text, 0)) != -1)
        return (get_the_line(line, &text, end_line));
    while ((result = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[result] = '\0';
        if (text == NULL)
            if (!(text = malloc(sizeof(char) * BUFFER_SIZE + 1)))
                return (-1);
        text = ft_strjoin_free(text, buff); //modifier le strjoin pour qu'il fonctionne meme si text == NULL
        if ((end_line = find('\n', text, 0)) != -1)
            return (get_the_line(line, &text, end_line));
    }
    return (get_the_line(line, &text, -1));
/*    if (text)
    {
        *line = ft_strdup(text);
        free(text);
        return (result);
    }
    *line = ft_strdup("");
    return (result);*/
}

#include <fcntl.h>

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
    (void)argc;
    char *name = argv[1];
    int fd = open(name, O_RDONLY);
    char *line;
//    int result = 1;
    printf("Contenu de %s : \n\n", name);
	if (!fd)
		return 1;
	while (get_next_line(fd, &line))
    {
//        printf("next line : %s(result = %d)\n", line, result);
        printf("%s\n", line);
        free(line);
    }
    if (line)
        free(line);
    close(fd);
    printf("nb malloc : %d\n", nb_malloc);
    printf("nb free : %d\n", nb_free);
    printf("adresses non liberees : \n");
    void (*aff)(void *);
    aff = &afficher;
    ft_lstiter(liste, aff);
    void (*del)(void *);
    del = &delete;
    ft_lstclear(&liste, del);
}

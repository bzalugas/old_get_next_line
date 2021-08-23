/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzalugas <bzalugas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:46:23 by bzalugas          #+#    #+#             */
/*   Updated: 2021/08/22 23:02:27 by bzalugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char **argv)
{
	char	**tab;
	char	*one;
	char	*two;
	char	*three;
	int		i;

	tab = malloc(sizeof(char) * 3);
	printf("sizeof(tab) = %lu\n", sizeof(tab));
	printf("tab : %p\ntab[0] : %p\n*tab : %p\n", tab,tab[0],*tab);
	one = malloc(sizeof(char) * 4);
	two = malloc(sizeof(char) * 4);
	three = malloc(sizeof(char) * 6);
	ft_strlcpy(one, "one", 4);
	ft_strlcpy(two, "two", 4);
	ft_strlcpy(three, "three", 6);
}

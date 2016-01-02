/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:53:11 by julio             #+#    #+#             */
/*   Updated: 2016/01/02 02:37:28 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_xy()
{

}

void	fill_grp(char *pack, group *grp, int *p, int k)
{
	int i;
	int j;
	tetrim *curr;

	i = -1;
	j = -1;
	curr = grp->curr;
	//printf("%d\n", *p);
	//curr->shape = (char **)malloc(sizeof(char *) * 4);
	while (++i < 4)
	{
		//curr->shape[i] = (char *)malloc(sizeof(char) * 5);
		while (++j < 5 && pack[*p] != '#')
			*p += 1;
		//printf("%c %d\n", pack[*p], *p);
		if (pack[*p] == '#')
		{
			*p = 26 * (k + 1);
			return ;
		}
		j = -1;
	}	
}

void	launcher(group *grp, char *pack)
{
	int i;
	int p;

	i = -1;
	p = 0;
	while (++i < grp->size)
	{
		insert(grp, ('A' + i));
		fill_grp(pack, grp, &p, i);
	}
	printf("pack:\n%s", pack);
	printf("grp.size = %d\n", grp->size);
	//show_group(grp);
}
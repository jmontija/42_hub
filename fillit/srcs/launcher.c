/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:53:11 by julio             #+#    #+#             */
/*   Updated: 2016/01/03 20:06:46 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int getdiez(char *pack)
{
	int i;
	int count;
	
	i = -1;
	count = 0;
	while (pack[++i] != '\n')
	{
		if (pack[i] == '#')
			count++;
	}
	return(count);
}
void	fill_grp(char *pack, group *grp, int *p)
{
	int i;
	int j;
	int y;
	int x;
	tetrim *curr;

	i = -1;
	j = -1;
	x = 0;
	y = 0;
	curr = grp->curr;
	curr->shape = (char **)malloc(sizeof(char *) * 5);
	while (++i < 4)
	{
		curr->shape[i] = (char *)malloc(sizeof(char) * 5);
		while (++j < 5)
		{
			if (pack[*p] == '.' && getdiez(&pack[*p]) > 0 &&
				((y > 0 && (pack[*p - 5] == '#' || pack[*p - 10] == '#')) ||
				 (y < 3 && (pack[*p + 5] == '#' || pack[*p + 10] == '#'))))
			{
				curr->shape[y][x] = ' ';//pack[*p];	
				x++;
			}
			if (pack[*p] == '#')
			{
				curr->shape[y][x] = curr->id;
				x++;
			}
			*p += 1;
		}
		if (x != 0)
			y++;
		x = 0;
		j = -1;
	}
	*p += 1;
	printf("%d\n", *p);
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
		fill_grp(pack, grp, &p);
	}
	printf("pack:\n%s", pack);
	show_group(grp);
	printf("grp.size = %d\n", grp->size);
}
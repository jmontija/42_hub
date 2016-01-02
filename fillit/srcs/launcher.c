/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:53:11 by julio             #+#    #+#             */
/*   Updated: 2016/01/02 01:52:28 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*

void	fill_shape(char *pack, char **tetris, int *p)
{
	int i;
	int j;

	//tetris[0][4][5]
	//printf("%d\n", *p);
	i = -1;
	j = -1;	
	if (!tetris && !pack)
		return ;
	while (++i < 4)
	{
		while (++j < 5)
		{
			if (tetris[i][0] != '\n')
			{
				tetris[i][j] = pack[*p];
				*p += 1;
			}
			else
			{
				*p += 1;
				return ;
			}
		}
		j = -1;
	}
	tetris[i] = NULL;
	*p += 1; // pour le '\n' entre les tetriminos;
	//printf("%d\n", *p);
}
*/
void	fill_grp(char *pack, group *grp, int *p)
{
	int i;
	int j;
	tetrim *curr;

	i = -1;
	j = -1;
	curr = grp->premier;
	printf("curr.id = %c\n", curr->id);
	curr->shape = (char **)malloc(sizeof(char *) * 4);
	while (++i < 4)
	{
		curr->shape[i] = (char *)malloc(sizeof(char) * 5);
		while (++j < 5)
		{
			if (pack[*p] != '\n')
				curr->shape[i][j] = pack[*p];
			*p += 1;
		}
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
	printf("grp.size = %d\n", grp->size);
	show_group(grp);
	/*insert(grp, 'A', 3, 1);
	insert(grp, 'A' + 1, 2, 2);
	show_group(grp);*/
}	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:53:11 by julio             #+#    #+#             */
/*   Updated: 2016/01/09 18:32:12 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_get_map(group *grp)
{
	int i;
	int j;

	i = -1;
	grp->map = (char **)malloc(sizeof(char *) * grp->mapLEN + 1);
	while (++i < grp->mapLEN)
	{
		j = -1;
		grp->map[i] = (char *)malloc(sizeof(char) * grp->mapLEN + 1);
		while (++j < grp->mapLEN)
			grp->map[i][j] = '.';
		grp->map[i][j] = '\0';
	}
	grp->map[i] = NULL;
}

void	ft_reset_map(group *grp)
{
	int i;

	i = 0;
	while (++i < grp->mapLEN)
	{
		if (grp->map[i])
		{
			free(grp->map[i]);
			grp->map[i] = NULL;
		}
	}
	ft_get_map(grp);
}

void coord_xy(group *grp, char **shape, int y)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		if (shape[i][0] == '\0')
			shape[i] = NULL;
		else
		{
			while (++j < 5)
			{
				if ( i == 0 && ft_isalpha(shape[i][j]))
					grp->curr->x += 1;
			}
			j = -1;
		}
	}
	shape[i] = NULL;
	grp->curr->y = y;
}
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
	curr->shape = (char **)malloc(sizeof(char *) * 5); // malloc a 4 + 1 pour eviter le segfault dans les conditions while (curr->shape[i]) // set le 5 a NULL(cf coord_xy)
	while (++i < 4)
	{
		curr->shape[i] = (char *)malloc(sizeof(char) * 5);
		while (++j < 5)
		{
			if (pack[*p] == '.' && getdiez(&pack[*p]) > 0 &&
				((y > 0 && pack[*p - 5] == '#') ||
					(y > 1 && (pack[*p - 5] == '#' || pack[*p - 10] == '#')) ||
					(y < 3 && pack[*p + 5] == '#') ||
					(y < 2 && (pack[*p + 5] == '#' || pack[*p + 10] == '#'))))
			{
				curr->shape[y][x] = pack[*p];	
				x++;
			}
			else if (pack[*p] == '#')
			{
				curr->shape[y][x] = curr->id;
				x++;
			}
			*p += 1;
		}
		curr->shape[y][x] = '\0';
		if (x != 0)
			y++;
		x = 0;
		j = -1;
	}
	*p += 1;
	coord_xy(grp, curr->shape, y);
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
	ft_get_map(grp);
	ft_resolve(grp);
	//printf("pack:\n%s", pack);
	//show_tetrim(grp);
	//printf("mapLEN: %d\n", grp->mapLEN);
	//printf("grp.size = %d\n", grp->size);
}
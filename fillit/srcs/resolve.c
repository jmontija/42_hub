/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 01:07:51 by julio             #+#    #+#             */
/*   Updated: 2016/01/09 18:37:58 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int count_dot_x(char *line)
{
	int i;

	i = 0;
	while (line[i] == '.' && line[i] != '\0')
		i++;
	return (i);
}

int	ft_allused(group *grp)
{
	tetrim *curr;
	int used;

	curr = grp->premier;
	used = 0;
	while (curr != NULL)
	{
		if (curr->used)
			used++;
		curr = curr->next;
	}
	//printf("USED = %d/%d\n", used, grp->size);
	if (used == grp->size)
		return (1);
	return (0);
}

int		ft_try(group *grp, tetrim *curr, int pos_x, int pos_y)
{
	int	i;
	int j;
	int check;

	i = -1;
	check = 0;
	while (curr->shape[++i] && grp->map[pos_y + i])
	{
		j = -1;
		while (curr->shape[i][++j] && grp->map[pos_y + i][pos_x + j])
		{
			if (curr->shape[i][j] == '.' && i == 0
				&& ft_try(grp, curr, pos_x - 1, pos_y))
				pos_x -= 1;
			else if (curr->shape[i][j] != '.' &&
				grp->map[pos_y + i][pos_x + j] && grp->map[pos_y + i][pos_x + j] == '.')
				check++;
		}
	}
	//printf("X = %d Y = %d ID = %c CHECK = %d\n", pos_x, pos_y, curr->id, check);
	if (check == 4)
		return (1);
	return (0);
}

void		ft_add_tetrim(group *grp, tetrim *curr, int pos_x, int pos_y)
{
	int	i;
	int j;

	i = -1;
	while (curr->shape[++i] && grp->map[pos_y + i])
	{
		j = -1;
		while (curr->shape[i][++j] && grp->map[pos_y + i][pos_x + j])
		{
			if (curr->shape[i][j] == '.' && i == 0
				&& ft_try(grp, curr, pos_x - 1, pos_y))
				pos_x -= 1;
			else if (curr->shape[i][j] != '.' &&
				grp->map[pos_y + i][pos_x + j] && grp->map[pos_y + i][pos_x + j] == '.')
				grp->map[pos_y + i][pos_x + j] = curr->shape[i][j];
		}
	}
	curr->used = true;
	//printf("ADD TETRIM %c\n", curr->id);
}

void	ft_rm_tetrim(group *grp, tetrim *curr)
{
	int x;
	int y;

	y = -1;
	while (++y < grp->mapLEN)
	{
		x = -1;
		while (++x < grp->mapLEN)
			if (grp->map[y][x] == curr->id)
				grp->map[y][x] = '.';
	}
	curr->used = false;
}

void		ft_check(group *grp, tetrim *curr, int x, int y)
{
	int dot_rest;
	//int i = 0;
	dot_rest = count_dot_x(&grp->map[y][x]);
	if (curr != NULL && !curr->used /*&& curr->x <= dot_rest*/ && ft_try(grp, curr, x, y))
	{
		ft_add_tetrim(grp, curr, x, y);
		ft_tracking(grp, curr->next);
		ft_rm_tetrim(grp, curr);
		//printf("FT_CHECK: LEAVING %c\n", curr->id);				
	}
}

void 	ft_tracking(group *grp, tetrim *curr)
{
	char **map;
	int x;
	int y = -1;

	map = grp->map;
	if (ft_allused(grp))
	{
		ft_save_check(grp);
	}
	while (++y < grp->mapLEN)
	{
		x = -1;
		while (++x < grp->mapLEN)
			ft_check(grp, curr, x, y);
	}
	if (curr->id == 'A')
	{
		show_tab("CURR_SAVE", grp->save);
		exit(0);
	}
}

void	ft_resolve(group *grp)
{

	ft_tracking(grp, grp->premier);
}


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
	j = -1;
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

int		ft_check(group *grp, tetrim *curr, int x, int y)
{
	int dot_rest;
	//int i = 0;

	dot_rest = count_dot_x(&grp->map[y][x]);
	if (curr != NULL && !curr->used && curr->x <= dot_rest && ft_try(grp, curr, x, y))
	{
		ft_add_tetrim(grp, curr, x, y);
		//printf("FT_CHECK: LEAVING %c\n", curr->id);				
		return (1);
	}
	return (0);
}

void	ft_tracking(group *grp, tetrim *curr, int x, int y)
{
	char **map;

	map = grp->map;
	if (y < grp->mapLEN && !ft_allused(grp))
	{
		if (map[y][x] == '\0')
			ft_tracking(grp, curr, 0, y + 1);
		else if (ft_isalpha(map[y][x]))
			ft_tracking(grp, curr, x + 1, y);
		else
		{
			if (ft_check(grp, curr, x, y))
			{
				curr = curr->next;
				ft_tracking(grp, curr, 0, 0);
			}
			else
			{
				ft_tracking(grp, curr, x + 1, y);
			}
		}
	}
	else if (ft_allused(grp))
		ft_save_check(grp);
	else if (y >= grp->mapLEN && !ft_allused(grp))
	{
		printf("HERE YOU GO %c\n", grp->curr->id);
	}
}

void	ft_resolve(group *grp)
{
	tetrim	*curr;

	curr = grp->premier;
	//grp->curr = curr->next;
	ft_tracking(grp, curr, 0, 0); //SEGFAULT POSSIBLE SI PLUS DE PIECE QUE LE MIN RANGE !
	//show_tab("CURR_MAP", grp->map);
	//show_tab("CURR_SAVE", grp->save);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 01:07:51 by julio             #+#    #+#             */
/*   Updated: 2016/01/05 12:56:21 by julio            ###   ########.fr       */
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

void		ft_add_tetrim(group *grp, tetrim *curr, int pos_x, int pos_y)
{
	int	i;
	int j;

	i = -1;
	j = -1;

	while (curr->shape[++i] && grp->map[pos_y + i])
	{
		while (curr->shape[i][++j] && grp->map[pos_y + i][pos_x + j])
		{
			if (curr->shape[i][j] != '.' && grp->map[pos_y + i][pos_x + j] == '.')
				grp->map[pos_y + i][pos_x + j] = curr->shape[i][j];
		}
		j = -1;
	}
	curr->used = true;
	printf("ADD_ID = %c\n", curr->id);
}

int		ft_try(group *grp, tetrim *curr, int pos_x, int pos_y)
{
	int	i;
	int j;
	int check;

	i = -1;
	j = -1;
	check = 0;

	while (curr->shape[++i] && grp->map[pos_y + i])
	{
		while (curr->shape[i][++j] && grp->map[pos_y + i][pos_x + j])
		{
			if (curr->shape[i][j] != '.' && grp->map[pos_y + i][pos_x + j] == '.')
				check++;
		}
		j = -1;
	}
	if (check == 4)
		return (1);
	return (0);
}

int		ft_check(group *grp, char *line, int x, int y)
{
	int dot_rest;
	tetrim	*curr;

	curr = grp->premier;
	dot_rest = count_dot_x(line);
	while (curr != NULL)
	{
		if (!curr->used && curr->x <= dot_rest)
		{
			if (ft_try(grp, curr, x, y))
			{
				ft_add_tetrim(grp, curr, x, y);
				return (1);
			}
		}
		curr = curr->next;
	}
	return (0);
}

void	ft_check_sq()
{

}

void	ft_tracking(group *grp, tetrim *curr, int x, int y)
{
	char **map;
	char **shape;

	map = grp->map;
	shape = curr->shape;

	if (y < grp->mapLEN)
	{
		if (ft_isalpha(map[y][x]))
			ft_tracking(grp, curr, x + 1, y);
		else if (map[y][x] == '\0')
			ft_tracking(grp, curr, 0, y + 1);
		else if (ft_check(grp, &map[y][x], x, y))
			ft_tracking(grp, curr, 0, 0);
		else
			ft_tracking(grp, curr, x + 1, y);
	}
	else if (y >= grp->mapLEN)
		ft_check_sq();
}

void	ft_resolve(group *grp)
{
	tetrim	*curr;

	curr = grp->premier;
	ft_tracking(grp, curr, 0, 0);
	show_tab(grp->map);
}

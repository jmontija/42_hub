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

int count_dot(char *line)
{
	int i;

	i = 0;
	while (line[i] == '.' && line[i] != '\0')
		i++;
	return (i);
}

void	ft_check(group *grp, char *line)
{
	int dot_rest;
	tetrim	*curr;

	curr = grp->premier;
	dot_rest = count_dot(line);
	/*while (curr != NULL)
	{
		if (!curr->used && curr->x <= dot_rest)
		{
			curr->used = true;
		}
	}*/
}

void	ft_check_sq()
{

}

void	ft_algo(group *grp, tetrim *curr, int x, int y)
{
	char **map;
	char **shape;

	map = grp->map;
	shape = curr->shape;

	if (y < grp->mapLEN)
	{
		if (ft_isalpha(map[y][x]))
			ft_algo(grp, curr, x + 1, y);
		else if (map[y][x] == '\0')
			ft_algo(grp, curr, 0, y + 1);
		else
		{
			ft_check(grp, &map[y][x]);
			ft_algo(grp, curr, x + 1, y);
		}
	}
	else if (y > grp->mapLEN)
		ft_check_sq();
}

void	ft_resolve(group *grp)
{
	tetrim	*curr;

	curr = grp->premier;
	ft_algo(grp, curr, 0, 0);
	show_tab(grp->map);
}
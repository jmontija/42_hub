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

void	ft_add_tetrim()
{
	
}

void	ft_algo(group *grp, tetrim *curr, int x, int y)
{
	char **map;
	char **shape;

	map = grp->map;
	shape = curr->shape;

	if (map[y][x] == '.')
	{
		if (x == 0 && y == 0)
			strcpy(map[y][x], );
	}
	/*else if (ft_isalpha(map[y][x]))
		ft_algo(group *grp, tetrim *curr, x + 1, y);
	else
		ft_algo(group *grp, tetrim *curr, 0, y + 1);*/
}

void	ft_resolve(group *grp)
{
	tetrim	*curr;

	curr = grp->premier;
	ft_algo(grp, curr, 0, 0);
}
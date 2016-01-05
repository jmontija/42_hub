/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 01:07:51 by julio             #+#    #+#             */
/*   Updated: 2016/01/05 01:43:00 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void get_map(group *grp)
{
	int i;
	int j;

	i = -1;
	j = -1;
	grp->map = (char **)malloc(sizeof(char *) * grp->mapLEN);
	while (++i < grp->mapLEN)
	{
		grp->map[i] = (char *)malloc(sizeof(char) * grp->mapLEN + 1);
		while (++j < grp->mapLEN)
			grp->map[i][j] = '.';
		grp->map[i][j] = '\0';
		printf("%d.\t%s\n", i+1, grp->map[i]);
		j = -1;
	}
}

void	ft_resolve(group *grp)
{
	/*char 	**map;
	int		i;
	tetrim	*curr;

	curr = grp->premier;*/
	get_map(grp);
	//map = grp->map;

}
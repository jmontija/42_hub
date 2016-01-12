/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:38:56 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/11 19:39:04 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqlen(group *grp, char **map)
{
	int i = -1;
	int x = 0;
	int y = 0;
	while (map[++i])
	{
		if (count_dot_x(map[i]) == grp->mapLEN)
		{
			free(map[i]);
			map[i] = NULL;
		}
		else
		{
			if (x < (int)ft_strlen(map[i]))
				x = (int)ft_strlen(map[i]);
			y++;
		}
	}
	//printf("sq_x=%d sq_y=%d\n", x, y);
	if (x > y)
		return (x);
	return (y);
}

void	ft_save_check(group *grp)
{
	//int i = -1;
	tetrim	*curr;

	curr = grp->premier;
	printf("sqLEN = %d\n", ft_sqlen(grp, grp->map));

	/*if (grp->save && (ft_sqlen(grp, grp->map) < ft_sqlen(grp, grp->save)))
	{
		printf("BETTER_SAVE_FOUND\n");
	}
	else if (!(grp->save))
	{
		printf("NO_SAVE\n");
		grp->save = (char **)malloc(sizeof(char *) * ft_sqlen(grp, grp->map) + 1);
		while (grp->map[++i])
			grp->save[i] = ft_strdup(grp->map[i]);
		grp->save[i] = NULL;
	}*/

	show_tab("CURR_MAP", grp->map);
	grp->mapLEN -= 1;
	ft_reset_map(grp);
	while (curr != NULL)
	{
		curr->used = false;
		printf("%c used = %d\n", curr->id, curr->used);
		curr = curr->next;
	}
	printf("LAST ID = %c\n", grp->curr->id);
	ft_tracking(grp, grp->premier, 0, 0);
}
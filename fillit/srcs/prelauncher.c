/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelauncher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 12:44:23 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_get_map(group *grp)
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

int		tetris_count(char *pack)
{
	int	i;
	int count;

	i = -1;
	count = 0;
	while (pack[++i])
	{
		if (pack[i] == '\n' && (i + 1 - count) % 5 != 0)
			count++;
	}
	count++;
	return (count);
}

char	*ft_orc(char *file)
{
	int					fd;
	int					ret;
	char				*pack;

	if (!(pack = (char *)malloc(sizeof(char) * BUFFER)))
		return (NULL);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(ret = read(fd, pack, BUFFER)))
		return (NULL);
	close(fd);
	return (pack);
}

void	pre_launcher(int argc, char **argv)
{
	group	*grp;
	char 	*pack;

	if (!(pack = ft_orc(argv[1])) || argc != 2)
	{
		ft_putstr("error\n");
		return ;
	}
	grp = init();
	grp->size = tetris_count(pack);
	grp->mapLEN = 4 + (grp->size / 4);
	ft_get_map(grp);
	launcher(grp, pack);
}

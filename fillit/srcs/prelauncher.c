/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelauncher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/09 18:31:52 by julio            ###   ########.fr       */
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

int		tetris_count(char *pack)
{
	int	i;
	int j = 0;
	int count;

	i = -1;
	count = 0;
	while (pack[++i])
	{	
		j++;
		dot++;
		if (pack[i] != '.' && pack[i] != '#' && pack[i] != '\n')
			ft_iserror();
		if (pack[i] == '\n')
		{
			if (j > 5)
				ft_iserror();
			j = 0;
		}
		if (pack[i] == '\n' && (i + 1 - count) % 5 != 0)
		{
			if (dot > 26)
			count++;
			j = 0;
			if (pack[i + 1] != '.' && pack[i + 1] != '#')
				ft_iserror();
		}
		/*else 
			ft_iserror();*/

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
	if (!(fd = open(file, O_RDONLY)) || fd < 1)
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
		ft_iserror();
	grp = init();
	grp->size = tetris_count(pack);
	grp->mapLEN = 12;
	ft_get_map(grp);
	launcher(grp, pack);
}

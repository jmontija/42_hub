/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelauncher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/16 19:02:57 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_map(group *grp)
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

int 	tetris_check(char *pack, int count, int *valid, int dot_x)
{
	int i;

	i = -1;
	while (pack[++i])
	{
		dot_x++;
		*valid += 1;
		if (pack[i] == '.' || pack[i] == '#' || pack[i] == '\n')
		{
			if (pack[i] == '\n')
			{
				dot_x > 5 ? ft_iserror() : 0;
				dot_x = 0;
			}
			if (pack[i] == '\n' && (i + 1 - count) % 5 != 0)
			{
				if ((pack[i + 1] != '.' && pack[i + 1] != '#') || (*valid != 21))
					ft_iserror();
				*valid = 0;
				count++;
			}
		}
		else
			ft_iserror();
	}
	return (count);
}

int		tetris_count(char *pack)
{
	int valid;
	int dot_x;
	int count;

	dot_x = 0;
	valid = 0;
	count = 0;
	count = tetris_check(pack, count, &valid, dot_x);
	count++;
	if (valid + 1 != 21)
		ft_iserror();
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
	char	*pack;

	if (!(pack = ft_orc(argv[1])) || argc != 2)
		ft_iserror();
	grp = init();
	grp->size = tetris_count(pack);
	grp->mapLEN = 12;
	ft_get_map(grp);
	launcher(grp, pack);
}

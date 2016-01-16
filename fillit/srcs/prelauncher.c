/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelauncher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/15 21:05:24 by julio            ###   ########.fr       */
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
	int valid;
	int dot_x = 0;
	int count;

	i = -1;
	valid = 0;
	count = 0;
	while (pack[++i])
	{	
		dot_x++;
		valid++;
		if (pack[i] == '.' || pack[i] == '#' || pack[i] == '\n')
		{
			if (pack[i] == '\n')
			{
				if (dot_x > 5)
				{
					printf("LIGNE TROP LONGUE\n");
					ft_iserror();
				}
				dot_x = 0;
			}
			if (pack[i] == '\n' && (i + 1 - count) % 5 != 0)
			{
				if (pack[i + 1] != '.' && pack[i + 1] != '#')
				{
					printf("NEXT TETRIM CHECK");
					ft_iserror();
				}
				printf("tetrim_size %d: %d\n",count, valid);
				if (valid != 21)
					ft_iserror();
				valid = 0;
				count++;
			}
		}
		else if (pack[i] != '.' && pack[i] != '#' && pack[i] != '\n')
		{
			printf("%c: INVALID CHAR\n", pack[i]);
			ft_iserror();
		}
	}
	count++;
	if (valid + 1 != 21)
		ft_iserror();
	printf("tetrim_size %d: %d\n",count, valid + 1);
	printf("COUNT=%d\n", count);
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

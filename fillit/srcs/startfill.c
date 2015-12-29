/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/29 04:56:27 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		tetris_count(char *pack)
{
	int	i;
	int count;

	i = -1;
	count = 0;
	while (pack[++i])
	{
		//printf("%d\n", i + 1 - count);
		if (pack[i] == '\n' && (i + 1 - count) % 5 != 0)
			count++;
	}
	count++;
	return (count);
}

void	tetris_fill(char *pack, char **tetris, int *p)
{
	int i;
	int j;

	//tetris[0][4][5]
	printf("%d\n", *p);
	i = -1;
	j = -1;	
	if (!tetris && !pack)
		return ;
	while (++i < 4)
	{
		while (++j < 5)
		{
			if (tetris[i][0] != '\n')
			{
				tetris[i][j] = pack[*p];
				*p += 1;
			}
			else
			{
				*p += 1;
				break;
			}
		}
		j = -1;
	}
	tetris[i] = NULL;
	*p += 1; // pour le '\n' entre les tetriminos;
	printf("%d\n", *p);
}

char	***tetris_pack(char *pack, char ***tetris)
{
	int i;
	int j;
	int p;

	//tetris[0][4][5]
	
	i = -1;
	j = -1;
	p = 0;
	while (++i < 5)
	{
		tetris[i] = (char **)malloc(sizeof(char *) * 4);
		while (++j < 5)
			tetris[i][j] = (char *)malloc(sizeof(char) * 5);
		tetris_fill(pack, tetris[i], &p);
		j = -1;
	}
	return (tetris);
}

void	launcher(int argc, char **argv)
{
	char	***tetris;
	char 	*pack;
	int		form_nb;

	if (!(pack = ft_orc(argv[1])) || argc != 2)
	{
		ft_putstr("error\n");
		return ;
	}
	form_nb = tetris_count(pack);
	tetris = (char ***)malloc(sizeof(char **) * form_nb);
	tetris_pack(pack, tetris);
	//form_define(pack, form_nb);

	printf("pack:\n%s", pack);
	printf("form_line 0: %s", tetris[3][0]);
	printf("form_line 0: %s", tetris[3][1]);
	printf("form_line 0: %s", tetris[3][2]);
	printf("form_line 0: %s", tetris[3][3]);
	printf("form_line 0: %s", tetris[3][4]);
	printf("\n");
	printf("form: %d\n", form_nb);
}

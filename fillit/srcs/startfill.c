/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/28 03:00:15 by jmontija         ###   ########.fr       */
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

int		form_count(char *pack)
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

/*void	form_define(char *pack, form_nb)
{
	int i;
	int diezes;
	int		**form_coord;

	i = -1;
	diezes = 0;

	form_coord = (int *)malloc(sizeof(int) * form_nb);
	if (!(form_coord))
		return ;
	while (pack[++i])
	{	
		if (pack[i] == '\n' && (i + 1 - form_idx) % 5 != 0)
			form_idx++;
		if (pack[i] == '#')
		{
			while (pack[i] == '#')
				diezes++;
		}
		form_coord[form_idx][0] = diezes;
	}
}*/

void	launcher(int argc, char **argv)
{
	char 	*pack;
	int		form_nb;

	if (!(pack = ft_orc(argv[1])) || argc != 2)
	{
		ft_putstr("error\n");
		return ;
	}
	form_nb = form_count(pack);
	//form_define(pack, form_nb);
	printf("pack:\n\n%s\n", pack);
	printf("form: %d\n", form_nb);
}

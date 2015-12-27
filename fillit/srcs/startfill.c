/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/27 20:48:06 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_orc(char **argv)
{
	int					fd;
	int					ret;
	char				*tab;

	if (!(tab = (char *)malloc(sizeof(char) * BUFFER)))
		return (NULL);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (NULL);
	if (!(ret = read(fd, tab, BUFFER)))
		return (NULL);
	close(fd);
	return (tab);
}

void	launcher(int argc, char **argv)
{
	char *pack;

	if (!(pack = ft_orc(argv)) || argc != 2)
	{
		ft_putstr("error\n");
		return ;
	}
	printf("pack:\n%s\n\n", pack);
	printf("argc: %d\n", argc);
}

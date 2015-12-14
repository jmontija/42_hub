/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:15:44 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/12 14:15:46 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int i;
	char 	*map;

	i = 0;
	map = ft_strdup(s);
	if (map)
	{
		while (map[i] != '\0')
		{
			f(map[i]);
			i++;
		}
	}
	return (map);
}

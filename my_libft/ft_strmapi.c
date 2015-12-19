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

/*char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char 	*map;

	i = 0;
	map = ft_strdup(s);
	if (map)
	{
		while (map[i] != '\0')
		{
			f(i, map[i]);
			i++;
		}
	}
	return (map);
}*/
	
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = NULL;
	if (s && f)
	{
		s2 = ft_strdup(s);
		while (s[i])
		{
			s2[i] = f(i, (char)s[i]);
			i++;
		}
	}
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 20:01:36 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/15 20:01:38 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_jecherche(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char	*ft_strstr(const char *s1, const char *s2)
{

	int i;
	char *str1;
	char *str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (*str2 == '\0')
		return (str1);
	if (str1)
	{
		while (str1[i] != '\0')
		{
			if (ft_jecherche(str1 + i, str2))
				return (str1 + i);
			i++;
		}
	}
	return (NULL);
}
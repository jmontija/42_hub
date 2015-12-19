/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 20:20:45 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/15 20:20:47 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static	int		ft_jencherche(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{

	size_t i;
	char *str1;
	char *str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (*str2 == '\0')
		return (str1);
	if (str1 && n > 0)
	{
		while (str1[i] != '\0' && i < n)
		{
			if (ft_jencherche(str1 + i, str2))
				return (str1 + i);
			i++;
		}
	}
	return (NULL);
}*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	n2;
	int		lastresult;

	if (*s2 == '\0')
		return ((char*)s1);
	n2 = ft_strlen(s2);
	lastresult = 1;
	while (n2 <= n && *s1 != '\0'
		&& (lastresult = ft_strncmp(s1, s2, n2)))
	{
		n--;
		s1++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:11:29 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/12 17:11:31 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char	*restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s1);
	if (s1 && s2)
	{
		while (i < n && s1[i] != '\0')
		{
			s1[i + len] = s2[i];
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return(NULL)
}

int		main(void)
{
	char	src[50] = "OLA";
	char	dst[50] = "HELLO";

	printf("%s\n", ft_strncat(dst, src, 10));
	return (0);
}
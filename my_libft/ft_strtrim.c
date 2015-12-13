/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:17:39 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/13 16:17:41 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	size_t len;
	char *str;

	i 	= 0;
	len = ft_lennospace(s);
	str = ft_strnew(len);
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			str[len] = s[i];
			len++;
		}
		i++;
	}
	str[len] = '\0';
	return (str);
}

int		main(void)
{
	char joe[] = "	      eyao         ";
	printf("%s\n", ft_strtrim(joe));
	return (0);
}

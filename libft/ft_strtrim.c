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

int	ft_isSpace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int		ft_len_noSpace(const char *str)
{
	unsigned int space_len;
	unsigned int len;
	unsigned int i;

	space_len = 0;
	i = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		while (str[i] && ft_isSpace(str[i++]))
			space_len++;
		if (i < len)
		{
			i = len - 1;
			while (str[i] && ft_isSpace(str[i--]))
				space_len++;
		}
	}
	return (len - space_len);
}

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	if (s)
	{
		len = ft_len_noSpace(s);
		if (len > 0)
		{
			i = 0;
			result = ft_strnew(len);
			if (result)
			{
				while (s[i] && ft_isSpace(s[i]))
					i++;
				if (!*(s + i))
					return (ft_strdup(""));
				ft_strncpy(result, &s[i], len);
				result[len] = '\0';
				return (result);
			}			
		}
	}
	return (ft_strdup(""));
}

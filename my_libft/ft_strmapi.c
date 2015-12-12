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

char	*ft_strmap(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char const *map

	map = ft_strdup(*s)
	if (map)
	{
		while (map[i] != '\0')
		{
			f(i, map[i]);
			i++;
		}
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:52 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/13 18:00:54 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word(char const *s, char c, size_t idx)
{

}

size_t	ft_wordnb(char const *s, char c)
{
	size_t word;
	size_t i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c)
				i++;
		}
		i++;
	}
	printf("%zu words:", word);
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char **split;
	size_t word;
	size_t i;

	i = 0;
	if (s)
	{
		word = ft_wordnb(s, c);
		*split = ft_strnew(word);
		while (i < word)
		{
			
		}
	}
	return (split);
}

int		main(void)
{
	char tosplit[] = "///ola//joe/comment///va//////";
	char **split;

	ft_strsplit(tosplit, '/');
	//printf("%s\n", split[0]);
	return (0);
}
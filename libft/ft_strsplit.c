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

static void	ft_fill(char const *s, char c, size_t idx, char *split)
{
	unsigned int word;
	unsigned int letter;
	unsigned int i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (word == idx)
				{
					split[letter] = s[i];
					letter++;
				}
				i++;
			}
			split[letter] = '\0';
			word++;
		}
		i++;
	}
}

unsigned int	ft_letter(char const *s, char c,size_t idx)
{
	unsigned int word;
	unsigned int letter;
	unsigned int i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[0] && s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (word == idx)
					letter++;
				i++;
			}
			word++;
		}
		i++;
	}
	return (letter);
}

unsigned int ft_wordnb(char const *s, char c)
{
	unsigned int word;
	unsigned int i;

	word 	= 0;
	i 		= 0;
	if (s && c)
	{
		if (s[i] && s[i] != c)
			word = 1;
		else
			word = 0;
		i++;
		while (s[0] && s[i] != '\0')
		{
			if (s[i - 1] == c && s[i] != c)
				word++;
			i++;
		}
	}
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char **split;
	unsigned int  word;
	unsigned int letter;
	unsigned int i;

	i = 0;
	split = NULL;
	if (s)
	{
		word = ft_wordnb(s, c);
		split = (char **)malloc(sizeof(char *) * (word + 1));
		if (split)
			split[word] = NULL;
		else
			return (NULL);
		while (i < word)
		{
			letter = ft_letter(s, c, i);
			split[i] = (char *)malloc(sizeof(char) * (letter + 1));
			if (split[i])
				ft_fill(s, c, i, split[i]);
			else
				return (NULL);
			i++;
		}
		return (split);
	}
	return (NULL);
}

/*int	main(void)
{
	char str[] = "";
	char	**stri;
	stri = ft_strsplit(str, '*');

	printf("%s\n", stri[0]);
	return (0);
}*/

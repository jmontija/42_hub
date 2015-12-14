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

void	ft_fill(char const *s, char c, size_t idx, char *split)
{
	size_t word;
	size_t letter;
	size_t i;

	word = 1;
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
	//return (split);
}

size_t	ft_letter(char const *s, char c,size_t idx)
{
	size_t word;
	size_t letter;
	size_t i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c)
			{
				if (word == idx)
					letter++;
				i++;
			}
		}
		i++;
	}
	printf("%zu letter\n", letter);
	return (letter);
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
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char **split;
	size_t word;
	size_t letter;

	if (s)
	{
		word = ft_wordnb(s, c);
		split = (char **)malloc(sizeof(char *) * word);
		//printf("%zu words\n", word);
		while (word)
		{
			letter = ft_letter(s, c, word);
			split[word - 1] = (char *)malloc(sizeof(char) * (letter + 1));
			ft_fill(s, c, word, split[word - 1]);
			printf("%zu words\n", word - 1);
			word--;
		}
	}
	return (split);
}

int		main(void)
{
	char tosplit[] = "yep///ola//joe/comment///////jarrrive//";
	char **split;
	int i;

	i = 0;
	split = ft_strsplit(tosplit, '/');

		printf("%s\n", split[0]);
		printf("%s\n", split[1]);
		printf("%s\n", split[2]);
		printf("%s\n", split[3]);
		printf("%s\n", split[4]);
		printf("%s\n", split[5]);
		printf("%s\n", split[6]);
	
	return (0);
}
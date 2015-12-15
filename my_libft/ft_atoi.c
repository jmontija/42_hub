/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:14:37 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/15 18:14:39 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nbr;
	int neg;
	int i;

	neg = 1;
	nbr = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' ||
		str[i] == '\t' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i]) - 48;
		i++;
	}
	return (neg * nbr);
}
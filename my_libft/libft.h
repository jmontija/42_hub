/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:24:59 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/10 17:25:04 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _LIBFT_H_
# define _LIBFT_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
size_t	ft_lennospace(char const *s);
char	*ft_strcpy(char *restrict dst, char *restrict src);
char	*ft_strnew(size_t size);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strncat(char	*restrict s1, const char *restrict s2, size_t n);

#endif
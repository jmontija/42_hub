/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:55:14 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 12:44:21 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define BUFFER (27*21) //

typedef struct		tetrim
{
	int				x;
	int				y;
	char			id;
	char			**shape;
	char			*coord;
	struct tetrim	*next;
}					tetrim;

typedef struct  group
{
    int 	size;
    int 	mapLEN;
    char	**map;
    struct tetrim *premier;
    struct tetrim *curr;
}				group;

group 	*init();
void	pre_launcher(int argc, char **argv);
void	launcher(group *_group, char *pack);
void 	insert(group *grp, char id);
void 	show_group(group *grp);
void	ft_resolve(group *grp);

#endif

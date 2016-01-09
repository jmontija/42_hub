/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:55:14 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/09 14:59:08 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define BUFFER (27*21) //

typedef int bool;
enum {false, true};

typedef struct		tetrim
{
	int				x;
	int				y;
	char			id;
	char			**shape;
	char			*coord;
	bool			used;
	struct tetrim	*next;
}					tetrim;

typedef struct 	checker
{
	int dot1;
	int dot2;
	int checker;
}				checker;

typedef struct  group
{
    int 	size;
    int 	mapLEN;
    char	**map;
    char	**save;
    struct tetrim *premier;
    struct tetrim *curr;
}				group;

group 	*init();
void	pre_launcher(int argc, char **argv);
void	launcher(group *_group, char *pack);
void 	insert(group *grp, char id);
void 	show_tetrim(group *grp);
void 	show_tab(char **tab);
void	ft_resolve(group *grp);

#endif

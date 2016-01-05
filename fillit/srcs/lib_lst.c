/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 00:02:15 by julio             #+#    #+#             */
/*   Updated: 2016/01/05 01:34:34 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void show_group (group *grp)
{
    int i;
    int j;
    i = -1;
    j = 0;
    if (!(grp))
        exit(0);
    tetrim *curr = grp->premier;
    while (curr != NULL)
    {
        printf("SHAPE: %d\n", ++j);
        while (curr->shape[++i])
            printf("1 %s\n", curr->shape[i]);
        i = -1;
        printf("X= %d\n", curr->x);
        printf("Y= %d\n", curr->y);
        curr = curr->next;
        printf("\n");
    }
}

void insert(group *grp, char id)
{
    tetrim *neW;

    neW = (tetrim*)malloc(sizeof(tetrim));
    if (!(neW))
        exit(0);
    neW->id = id;
    neW->x = 0;
    neW->y = 0;
    neW->next = NULL;
    if (grp->curr != NULL)
        grp->curr->next = neW;
    else
        grp->premier = neW;
    grp->curr = neW;
}

group *init()
{
    group *grp = (group*)malloc(sizeof(group));
    if (!(grp))
        exit(0);
    grp->premier = NULL;
    grp->curr = NULL;
    return (grp);
}
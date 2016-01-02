/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 00:02:15 by julio             #+#    #+#             */
/*   Updated: 2016/01/02 01:46:16 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void show_group (group *grp)
{
    if (!(grp))
        exit(0);
    tetrim *curr = grp->premier;
    while (curr != NULL)
    {
        printf("id %c\n", curr->id);
        printf("1 %s\n", curr->shape[0]);
        printf("2 %s\n", curr->shape[1]);
        printf("3 %s\n", curr->shape[2]);
        printf("4 %s\n", curr->shape[3]);
        curr = curr->next;
    }
    printf("NULL\n");
}

void insert(group *grp, char id)
{
    tetrim *neW = (tetrim*)malloc(sizeof(tetrim));
    if (!(neW))
        exit(0);
    neW->id = id;
    neW->next = grp->premier;
    grp->premier = neW;
}

group *init()
{
    group *grp = (group*)malloc(sizeof(group));
    if (!(grp))
        exit(0);
    grp->premier = NULL;
    return (grp);
}
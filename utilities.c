/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:23 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/14 06:45:22 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"


t_cord get_coordinates(char **map)
{
    t_cord cord;
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[j])
    {
        while (map[j][i])
        {
            if (map[j][i] == 'P')
            {
                cord.x = i;
                cord.y = j;
                break;
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (cord);
}
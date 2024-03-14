/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:42 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/14 06:31:12 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"

int check_collectibles(char **map)
{
    int i;
    int collectibles;

    i = 0;
    collectibles = 0;
    while (*map)
    {
        while ((*map)[i])
        {
            if ((*map)[i] == 'C')
                collectibles++;
            i++;
        }
        i = 0;
        map++;
    }
    return (collectibles);
}
int check_player(char **map)
{
    int i;
    int player;

    i = 0;
    player = 0;
    while (*map)
    {
        while ((*map)[i])
        {
            if ((*map)[i] == 'P')
                player++;
            i++;
        }
        i = 0;
        map++;
    }
    return (player);
}

void flood_fill(char **map,int x, int y)
{
    
    if( x < 0  || y < 0 || map[y][x] == '1' || map[y][x] == 'P')
        return;
    map[y][x] = 'P';
    flood_fill(map,x+1,y);
    flood_fill(map,x-1,y);
    flood_fill(map,x,y+1);
    flood_fill(map,x,y-1);
}

int check_exit(char **map)
{
    int i;
    int exit;

    i = 0;
    exit = 0;
    while (*map)
    {
        while ((*map)[i])
        {
            if ((*map)[i] == 'E')
                exit++;
            i++;
        }
        i = 0;
        map++;
    }
    return (exit);
}

int is_rectangular(char **map)
{
    int i;
    int len;

    i = -1;
    len = 0;
    while ((*map)[i++] != '\n')
        len++;
    while (*map)
    {
        i = 0;
        while ((*map)[i])
            i++;
        if (i != len)
            return (1);
        map++;
    }
    return (0);
}

int check_walls(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    int count = 0;
    while (map[j])
    {
        while (map[0][i] && map[0][i] != '\n')
        {
            if (map[0][1] != '1')
                return (1);
            i++;
        }
        if (map[j][0] != '1')
             return (1);
        if(map[j][ft_strlen(map[j])-2] != '1')
                return(1);
        i = 0;
        j++;
    }
    j--;
    i = 0;
    while (map[j][i]  && map[j][i] != '\n')
    {
        if (map[j][i] != '1')
            return (1);
        i++;
    }
    return (0);
}

int check_elements(char **map)
{
    int i;

    i = 0;
    while (*map)
    {
        while ((*map)[i])
        {
            if ((*map)[i] != '1' && (*map)[i] != '0' && (*map)[i] != 'P' 
                && (*map)[i] != 'C' && (*map)[i] != 'E' && (*map)[i] != '\n')   
                return (1);
            i++;
        }
        i = 0;
        map++;
    }
    return (0);
}

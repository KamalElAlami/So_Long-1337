/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:33 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/14 05:13:28 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"

void ft_perror(char *msg)
{
    printf("%s", msg);
    exit(EXIT_FAILURE);
}

int count_len(char *av)
{
    int fd  = open(av,O_RDONLY);
    if(fd == -1)
        return(1);
    int count = 0;
    while(1)
    {
        char *str = get_next_line(fd);
        if(!str)
            break;
        count++;
        free(str);
    }
    close(fd);
    return(count);
}
void parse_map(char **map)
{
    if (check_collectibles(map) < 1)
        ft_perror("there is no collectibles");
    if (check_player(map) < 1 || check_player(map) > 1)
        ft_perror("there is no player or there are several players in the map");
    if (check_exit(map) < 1 || check_exit(map) > 1)
        ft_perror("there is no exit or there is several exits in the map");
    if (is_rectangular(map) == 1)
        ft_perror("map is not rectangular");
    if (check_walls(map) == 1)
        ft_perror("map is not serrounded by walls");
}
    
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;
        int fd;
        char **map;
        char **smap;
        
        fd = open(av[1], O_RDONLY);
        if(fd == -1)
            return(1);
        map = malloc(sizeof(char *) * count_len(av[1]) + 1);
        smap = malloc(sizeof(char *) * (count_len(av[1])) + 1);
        i = 0;
        int count = 0;
        while(1)
        {
            map[i] = get_next_line(fd);
            if(!map[i])
                break;
            i++;
        }
        map[++i] = NULL;
        close(fd);
        i = 0;
        while (map[i])
        {
            smap[i] = ft_strdup(map[i]);
            i++;
        }
        smap[i] = NULL;
        i = 0;
        parse_map(map);
    }
    else{
        printf("something is wrong");
    }
}
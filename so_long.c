/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:33 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/16 00:17:30 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"
#include "mlx.h"

void ft_perror(char *msg)
{
    ft_printf("%s", msg);
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
    if (check_elements(map) == 1)
        ft_perror("there is a strange element other than P E C 1 0");
}
void check_path(char *path)
{
    int i;
    
    i = 0;
    if (!path)
        ft_perror("map path is not valid or there is no map");
    while (path[i])
    {
        if (path[i] == '.')
        {
            if(ft_strcmp(path + i, ".ber"))
                ft_perror("invalid map extension");
        }
        i++;
    }
}
void charge_map(int fd, char **buffer)
{
    int i;
    
    i = 0;
    while(1)
    {
        buffer[i] = get_next_line(fd);
        if(!buffer[i])
            break;
        i++;
    }
    buffer[++i] = NULL;
    close(fd);
}
void clone_map(char **map, char **buffer)
{
    int i;

    i = 0;
    while (map[i])
    {
        buffer[i] = ft_strdup(map[i]);
        i++;
    }
    buffer[i] = NULL;
}
int move(int key, char **map)
{
    printf("%s\n",*map);
    printf("%d\n",key);
    return(0);
}
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;
        int fd;
        char **map;
        char **smap;
        t_cord coord;
        void *mlx = mlx_init();

        check_path(av[1]);
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return(1);
        map = malloc(sizeof(char *) * count_len(av[1]) + 1);
        smap = malloc(sizeof(char *) * (count_len(av[1])) + 1);
        charge_map(fd, map);
        clone_map(map, smap);
        parse_map(map);
        flood_fill(smap, coord.x, coord.y);
        coord = get_coordinates(map);
        map_size(map, &coord);
        load_graphics(map, mlx, coord.Xlen, coord.Ylen);
        mlx_hook(mlx, 2, 0,move, map);
        mlx_loop(mlx);
        i = 0;
        while (smap[i])
            printf("%s", smap[i++]);
    }
    else{
        printf("something is wrong check your arguments");
    }
}
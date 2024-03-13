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
// typedef struct t_cord{
//     int x;
//     int y;
// }t_cord;

// void floid_fill(char **map,int x, int y)
// {
//     if( x < 0  || y < 0 || map[y][x] == '1' || map[y][x] == 'C')
//         return;
//     map[y][x] = 'C';
//     floid_fill(map,x+1,y);
//     floid_fill(map,x-1,y);
//     floid_fill(map,x,y+1);
//     floid_fill(map,x,y-1);
// }

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

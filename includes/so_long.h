#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int check_collectibles(char **map);
void flood_fill(char **map,int x, int y);
int is_rectangular(char **map);
int check_player(char **map);
int check_exit(char **map);
int check_walls(char **map);


#endif
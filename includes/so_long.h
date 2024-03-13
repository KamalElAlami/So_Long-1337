#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int check_collectibles(char **map);
void floid_fill(char **map,int x, int y);

#endif
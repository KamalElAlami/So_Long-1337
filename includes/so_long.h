#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>

#define HEIGHT 32
#define WIDTH 32

typedef struct t_cord {
    int x;
    int y;
    int Xlen;
    int Ylen;
} t_cord;

int check_collectibles(char **map);
void flood_fill(char **map,int x, int y);
int is_rectangular(char **map);
int check_player(char **map);
int check_exit(char **map);
int check_walls(char **map);
int check_elements(char **map);
t_cord get_coordinates(char **map);
void map_size(char **map, t_cord *cooord);
void load_graphics(char **map, void *mlx, int width, int height);


#endif
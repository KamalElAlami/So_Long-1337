#include "./includes/get_next_line.h"
#include "./includes/so_long.h"
#include <string.h>


int check_collectibles(int fd)
{
    int collectible;
    char *line;

    collectible = 0;
    while (line = get_next_line(fd))
    {
        while(*line)
        {
            if (*line == 'C')
                collectible++;
            line++;
        }
    }
    return (collectible);
}

int check_player(int fd)
{
    int player;
    char *line;

    player = 0;
    while (line = get_next_line(fd))
    {
        while(*line)
        {
            if (*line == 'C')
                player++;
            line++;
        }
    }
    return (player);
}
int check_exit(int fd)
{
    int exit;
    char *line;

    exit = 0;
    while (line = get_next_line(fd))
    {
        while(*line)
        {
            if (*line == 'C')
                exit++;
            line++;
        }
    }
    return (exit);
}
void check_wall(int fd)
{
    char *line;
    int i;

    i = 0;
    while (line = get_next_line(fd))
    {
        while (line[i])
        {
            if (line[0] != '1')
            {
                printf("map is not serrounded by walls");
                exit(EXIT_FAILURE);
            }
            if (line[i] == '\n')
            {
                i--;
                if (line[i] != '1')
                {
                printf("map is not serrounded by walls");
                exit(EXIT_FAILURE);
                }
                i++;
            }
            i++;
        }
        i = 0;
    }
}
// int is_rectangle(int fd)
// {

// }

int main(void)
{
    int fd;

    fd = open("./maps/map1.ber", O_RDONLY);

    // printf("%d", check_collectibles(fd));
    check_wall(fd);

}
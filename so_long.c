#include "includes/get_next_line.h"
#include "includes/so_long.h"

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
    
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int fd;
        fd = open(av[1], O_RDONLY);
        if(fd == -1)
            return(1);
        char **map = malloc(sizeof(char* ) * count_len(av[1]));
        int i = 0;
        while(1)
        {
            map[i] = get_next_line(fd);
            if(!map[i])
                break;
            i++;
        }
       i = 0;
        floid_fill(map,2,2);
        while(map[i])
            printf("%s",map[i++]);
        //printf("%d", check_collectibles(map));
    }
    else{
        printf("something is wrong");
    }
}
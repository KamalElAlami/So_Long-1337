/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:23 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/17 17:31:51 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

t_cord	get_coordinates(char **map)
{
	t_cord	cord;
	int		i;
	int		j;

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

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'R' || map[y][x] == 'X' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'R';
		return;
	}
	else
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_elements(char **map)
{
	int	i;

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

void map_size(char **map, t_cord *cooord)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while (map[j])
		j++;
	while (map[0][i])
		i++;
	cooord->Xlen = i;
	cooord->Ylen = j;
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

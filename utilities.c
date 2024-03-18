/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:23 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/18 00:42:05 by kael-ala         ###   ########.fr       */
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
				break ;
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
		return ;
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

void	map_size(char **map, t_cord *cooord)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[j])
		j++;
	while (map[0][i])
		i++;
	cooord->x_len = i;
	cooord->y_len = j;
}

int	count_len(char *av)
{
	int		fd;
	int		count;
	char	*str;

	fd = open(av, O_RDONLY);
	count = 0;
	if (fd == -1)
		return (1);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		count++;
		free(str);
	}
	close(fd);
	return (count);
}

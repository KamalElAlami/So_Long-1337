/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:23 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/21 00:28:22 by kael-ala         ###   ########.fr       */
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

void	flood_fill(char **map, int len, int x, int y)
{
	if (x < 0 || y < 0 || y >= len)
		return ;
	if (map[y][x] == 'R' || map[y][x] == 'X' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'R';
		return ;
	}
	else
		map[y][x] = 'X';
	flood_fill(map, len, x + 1, y);
	flood_fill(map, len, x - 1, y);
	flood_fill(map, len, x, y + 1);
	flood_fill(map, len, x, y - 1);
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

void	free_array(char **array)
{
	int	j;

	j = 0;
	if (!array)
		exit(1);
	while (array[j])
		free(array[j++]);
	free(array);
}

int	close_win(void)
{
	ft_printf(GREEN "Bye\n" RESET);
	exit (0);
	return (0);
}

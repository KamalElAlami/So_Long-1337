/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:22 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/21 08:04:12 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

int	move_up(char **map, int y, int x)
{
	if (map[y -1][x] == '0' || map[y - 1][x] == 'C')
	{
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		return (0);
	}
	return (1);
}

int	move_left(char **map, int y, int x)
{
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		return (0);
	}
	return (1);
}

int	move_down(char **map, int y, int x)
{
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
	{
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		return (0);
	}
	return (1);
}

int	move_right(char **map, int y, int x)
{
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		return (0);
	}
	return (1);
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

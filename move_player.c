/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:22 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/18 06:55:20 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

void move_up(char **map, int y, int x)
{
    	if (map[y -1][x] == '0'
			|| map[y - 1][x] == 'C')
		{
			map[y][x] = '0';
			map[y - 1][x] = 'P';
		}
}

void move_left(char **map, int y, int x)
{
    	if (map[y][x - 1] == '0'
			|| map[y][x - 1] == 'C')
		{
			map[y][x] = '0';
			map[y][x - 1] = 'P';
		}
}

void move_down(char **map, int y, int x)
{
    	if (map[y + 1][x] == '0'
			|| map[y + 1][x] == 'C')
		{
			map[y][x] = '0';
			map[y + 1][x] = 'P';
		}
}

void move_right(char **map, int y, int x)
{
    	if (map[y][x + 1] == '0'
			|| map[y][x + 1] == 'C')
		{
			map[y][x] = '0';
			map[y][x + 1] = 'P';
		}
}
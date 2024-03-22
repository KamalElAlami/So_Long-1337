/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utilities_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:57:08 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/22 03:43:57 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"
#include "../includes/ft_printf.h"

void	up_event(char **map, int y, int x, int *key_press)
{
	if (!(move_up(map, y, x)))
		ft_printf("Move Number : %d\n", (*key_press)++);
	else if (map[y - 1][x] == 'E'
		&& check_collectibles(map) == 0)
	{
		ft_printf(GREEN"You beat the game");
		exit(EXIT_SUCCESS);
	}
}

void	left_event(char **map, int y, int x, int *key_press)
{
	if (!(move_left(map, y, x)))
		ft_printf("Move Number : %d\n", (*key_press)++);
	else if (map[y][x - 1] == 'E'
		&& check_collectibles(map) == 0)
	{
		ft_printf(GREEN"You beat the game");
		exit(EXIT_SUCCESS);
	}
}

void	down_event(char **map, int y, int x, int *key_press)
{
	if (!(move_down(map, y, x)))
		ft_printf("Move Number : %d\n", (*key_press)++);
	else if (map[y + 1][x] == 'E'
		&& check_collectibles(map) == 0)
	{
		ft_printf(GREEN"You beat the game");
		exit(EXIT_SUCCESS);
	}
}

void	right_event(char **map, int y, int x, int *key_press)
{
	if (!(move_right(map, y, x)))
		ft_printf("Move Number : %d\n", (*key_press)++);
	else if (map[y][x + 1] == 'E'
		&& check_collectibles(map) == 0)
	{
		ft_printf(GREEN"You beat the game");
		exit(EXIT_SUCCESS);
	}
}

void	destroy_images_check( int *m, void *mlx, t_assets all)
{
	if (*m)
	{
		destroy_imgs(mlx, all);
		*m = 1;
	}
}

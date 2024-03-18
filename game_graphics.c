/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:22 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/18 06:59:38 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

t_assets	assets_img(void *mlx)
{
	t_assets	all;
	int			x;
	int			y;

	y = 32;
	x = 32;
	all.ground_img = mlx_xpm_file_to_image(mlx, "./assets/grace.xpm", &x, &y);
	all.wall_img = mlx_xpm_file_to_image(mlx, "./assets/stone.xpm", &x, &y);
	all.player_img = mlx_xpm_file_to_image(mlx, "./assets/character.xpm", &x, &y);
	all.collect_img = mlx_xpm_file_to_image(mlx, "./assets/collect.xpm", &x, &y);
	all.exit_img = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &x, &y);
	return (all);
}

void	destroy_imgs(void *mlx, t_assets all)
{
	mlx_destroy_image(mlx, all.collect_img);
	mlx_destroy_image(mlx, all.exit_img);
	mlx_destroy_image(mlx, all.ground_img);
	mlx_destroy_image(mlx, all.player_img);
	mlx_destroy_image(mlx, all.wall_img);
}

void	apply(char **map, void *mlx, void *mlx_win, t_assets all)
{
	int			i;
	int			j;
	int			x;
	int			y;
	static int	m;

	y = 32;
	x = 32;
	j = 0;
	if (m)
	{
		destroy_imgs(mlx, all);
		m = 1;
	}
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(mlx, mlx_win, all.ground_img, i * 32, j * 32);
			if (map[j][i] == '1')
				mlx_put_image_to_window(mlx, mlx_win, all.wall_img, i * 32, j * 32);
			if (map[j][i] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, all.player_img, i * 32, j * 32);
			if (map[j][i] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, all.collect_img, i * 32, j * 32);
			if (map[j][i] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, all.exit_img, i * 32, j * 32);
			i++;
		}
		j++;
	}
}

int	key_hook(int key, t_infos *info)
{
	int		i;
	int		j;
	int		key_press;
	t_cord	siko;

	j = 0;
	i = 0;
	key_press = 0;
	siko = get_coordinates(info ->map);
	if (key == 13)
	{
		if (info->map[siko.y -1][siko.x] == '0'
			|| info->map[siko.y -1][siko.x] == 'C')
		{
			info -> map[siko.y][siko.x] = '0';
			info -> map[siko.y - 1][siko.x] = 'P';
			key_press++;
			ft_printf("Move Number : %d", key_press);
		}
	}
	else if (key == 0)
	{
		if (info->map[siko.y][siko.x - 1] == '0'
			|| info->map[siko.y][siko.x -1] == 'C')
		{
			info -> map[siko.y][siko.x] = '0';
			info -> map[siko.y][siko.x - 1] = 'P';
			key_press++;
			ft_printf("Move Number : %d", key_press);
		}
	}
	else if (key == 1)
	{
		if (info -> map[siko.y + 1][siko.x] == '0'
			|| info -> map[siko.y + 1][siko.x] == 'C')
		{
			info -> map[siko.y][siko.x] = '0';
			info -> map[siko.y + 1][siko.x] = 'P';
			key_press++;
			ft_printf("Move Number : %d", key_press);
		}
	}
	else if (key == 2)
	{
		if (info -> map[siko.y][siko.x + 1] == '0'
			|| info -> map[siko.y][siko.x + 1] == 'C')
		{
			info -> map[siko.y][siko.x] = '0';
			info -> map[siko.y][siko.x + 1] = 'P';
			key_press++;
			ft_printf("Move Number : %d", key_press);`
		}
		else if (info -> map[siko.y][siko.x + 1] == 'E' 
				&& check_collectibles(info->map) == 0)
				exit(0);
	}
	else if (key == 53)
		exit(0);
	apply(info->map, info->mlx, info->mlx_win, info->all);
	return (0);
}

void	load_graphics(char **map, int width, int height)
{
	void		*mlx;
	int			k;
	void		*mlx_win;
	t_assets	all;
	t_infos		info;

	mlx = mlx_init();
	all = assets_img(mlx);
	mlx_win = mlx_new_window(mlx, (width -1) * 32, height * 32, "So Long Game");
	apply(map, mlx, mlx_win, all);
	info.map = map;
	info.mlx = mlx;
	info.mlx_win = mlx_win;
	info.all = all;
	k = mlx_hook(mlx_win, 2, 0, key_hook, &info);
	mlx_loop(mlx);
}

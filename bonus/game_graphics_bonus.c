/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:22 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/22 04:08:53 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"
#include "../includes/ft_printf.h"

t_assets	assets_img(void *mlx)
{
	t_assets	all;
	int			x;
	int			y;

	y = 64;
	x = 64;
	all.ground = mlx_xpm_file_to_image(mlx, "./assets/grace.xpm", &x, &y);
	if (!(all.ground))
		exit(EXIT_FAILURE);
	all.wall = mlx_xpm_file_to_image(mlx, "./assets/stone.xpm", &x, &y);
	if (!(all.wall))
		exit(EXIT_FAILURE);
	all.play = mlx_xpm_file_to_image(mlx, "./assets/character.xpm", &x, &y);
	if (!(all.play))
		exit(EXIT_FAILURE);
	all.coll = mlx_xpm_file_to_image(mlx, "./assets/collect.xpm", &x, &y);
	if (!(all.coll))
		exit(EXIT_FAILURE);
	all.exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &x, &y);
	if (!(all.exit))
		exit(EXIT_FAILURE);
	return (all);
}

void	destroy_imgs(void *mlx, t_assets all)
{
	mlx_destroy_image(mlx, all.coll);
	mlx_destroy_image(mlx, all.exit);
	mlx_destroy_image(mlx, all.ground);
	mlx_destroy_image(mlx, all.play);
	mlx_destroy_image(mlx, all.wall);
}

void	apply_images(char **map, void *mlx, void *mlx_win, t_assets all)
{
	int			i;
	int			j;
	static int	m;

	j = 0;
	destroy_images_check(&m, mlx, all);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(mlx, mlx_win, all.ground, i * 64, j * 64);
			if (map[j][i] == '1')
				mlx_put_image_to_window(mlx, mlx_win, all.wall, i * 64, j * 64);
			if (map[j][i] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, all.play, i * 64, j * 64);
			if (map[j][i] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, all.coll, i * 64, j * 64);
			if (map[j][i] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, all.exit, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

int	key_hook(int key, t_infos *info)
{
	int				i;
	int				j;
	static int		key_press;
	t_cord			coord;

	j = 0;
	i = 0;
	coord = get_coordinates(info ->map);
	if (key == 13)
		up_event(info->map, coord.y, coord.x, &key_press);
	else if (key == 0)
		left_event(info->map, coord.y, coord.x, &key_press);
	else if (key == 1)
		down_event(info->map, coord.y, coord.x, &key_press);
	else if (key == 2)
		right_event(info->map, coord.y, coord.x, &key_press);
	else if (key == 53)
		exit(0);
	apply_images(info->map, info->mlx, info->mlx_win, info->all);
	return (0);
}

void	load_graphics(char **map, int width, int height)
{
	void		*mlx;
	void		*mlx_win;
	t_assets	all;
	t_infos		info;

	mlx = mlx_init();
	all = assets_img(mlx);
	mlx_win = mlx_new_window(mlx, (width -1) * 64, height * 64, "So Long Game");
	apply_images(map, mlx, mlx_win, all);
	info.map = map;
	info.mlx = mlx;
	info.mlx_win = mlx_win;
	info.all = all;
	mlx_hook(mlx_win, 2, 0, key_hook, &info);
	mlx_hook(mlx_win, 17, 0, close_win, NULL);
	mlx_loop(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:35:20 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/21 08:10:39 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

typedef struct t_assets
{
	void	*wall;
	void	*ground;
	void	*play;
	void	*exit;
	void	*coll;
}	t_assets;

typedef struct t_infos
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	t_assets	all;
}	t_infos;

typedef struct t_cord
{
	int	x;
	int	y;
	int	x_len;
	int	y_len;
}	t_cord;

int		check_player(char **map);
int		check_exit(char **map);
int		check_walls(char **map);
int		check_elements(char **map);
void	check_path(char *path);
int		check_validity(char **map);
int		check_collectibles(char **map);

void	flood_fill(char **map, int len, int x, int y);
int		is_rectangular(char **map);
int		parse_map(char **map, char **smap);
t_cord	get_coordinates(char **map);
void	map_size(char **map, t_cord *cooord);
void	load_graphics(char **map, int width, int height);
void	ft_perror(char *msg, char **map, char **smap, char *optional);
void	free_array(char **array);
int		count_len(char *av);
void	destroy_imgs(void *mlx, t_assets all);
void	destroy_images_check( int *m, void *mlx, t_assets all);
int		close_win(void);

int		move_up(char **info, int y, int x);
int		move_left(char **map, int y, int x);
int		move_down(char **map, int y, int x);
int		move_right(char **map, int y, int x);

void	up_event(char **map, int y, int x, int *key_press);
void	left_event(char **map, int y, int x, int *key_press);
void	down_event(char **map, int y, int x, int *key_press);
void	right_event(char **map, int y, int x, int *key_press);

#endif
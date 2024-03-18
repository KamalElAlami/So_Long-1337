/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 00:35:20 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/18 00:41:47 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct t_assets
{
	void	*wall_img;
	void	*ground_img;
	void	*player_img;
	void	*exit_img;
	void	*collect_img;
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

int		count_len(char *av);
int		check_collectibles(char **map);
void	flood_fill(char **map, int x, int y);
int		is_rectangular(char **map);
int		check_player(char **map);
int		check_exit(char **map);
int		check_walls(char **map);
int		check_elements(char **map);
void	check_path(char *path);
int		check_validity(char **map);
void	parse_map(char **map);
t_cord	get_coordinates(char **map);
void	map_size(char **map, t_cord *cooord);
void	load_graphics(char **map, int width, int height);
void	ft_perror(char *msg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:33 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/18 00:45:19 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"
#include "mlx.h"

void	ft_perror(char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	charge_map(int fd, char **buffer)
{
	int	i;

	i = 0;
	while (1)
	{
		buffer[i] = get_next_line(fd);
		if (!buffer[i])
			break ;
		i++;
	}
	buffer[++i] = NULL;
	close(fd);
}

void	clone_map(char **map, char **buffer)
{
	int	i;

	i = 0;
	while (map[i])
	{
		buffer[i] = ft_strdup(map[i]);
		i++;
	}
	buffer[i] = NULL;
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	**map;
	char	**smap;
	t_cord	coord;

	if (ac == 2)
	{
		check_path(av[1]);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		map = malloc(sizeof(char *) * (count_len(av[1]) + 1));
		smap = malloc(sizeof(char *) * (count_len(av[1]) + 1));
		charge_map(fd, map);
		clone_map(map, smap);
		parse_map(map);
		coord = get_coordinates(map);
		flood_fill(smap, coord.x, coord.y);
		if (check_validity(smap))
			ft_perror("Your map is not valid");
		map_size(map, &coord);
		load_graphics(map, coord.x_len, coord.y_len);
	}
	else
	{
		printf("something is wrong check your arguments");
	}
}

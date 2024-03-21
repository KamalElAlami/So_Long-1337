/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:33 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/21 08:13:48 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

char	**charge_map(int fd, int len)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char *) * (len + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		buffer[i] = get_next_line(fd);
		if (!buffer[i])
			break ;
		i++;
	}
	i = i - 1;
	if (buffer[i][ft_strlen(buffer[i]) - 1] == '\n')
		ft_perror("Error \nNew line in the end of the map", buffer, NULL, NULL);
	close(fd);
	return (buffer);
}

char	**clone_map(char **map, int len)
{
	int		i;
	char	**smap;

	i = 0;
	smap = malloc(sizeof(char *) * (len + 1));
	if (!smap)
		return (NULL);
	while (map[i])
	{
		smap[i] = ft_strdup(map[i]);
		i++;
	}
	smap[i] = NULL;
	return (smap);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**map;
	char	**smap;
	int		len;
	t_cord	coord;

	if (ac != 2)
		return (ft_printf("something is wrong check your arguments"), 1);
	check_path(av[1]);
	fd = open(av[1], O_RDONLY);
	len = count_len(av[1]);
	if (fd == -1)
		ft_perror("Error \nInvalide File Map", NULL, NULL, NULL);
	map = charge_map(fd, len);
	smap = clone_map(map, len);
	parse_map(map, smap);
	coord = get_coordinates(map);
	map_size(map, &coord);
	if (coord.x_len > 80 || coord.y_len > 44)
		ft_perror("Your map is not valid", map, smap, NULL);
	flood_fill(smap, len, coord.x, coord.y);
	if (check_validity(smap))
		ft_perror("Your map is not valid", map, smap, NULL);
	load_graphics(map, coord.x_len, coord.y_len);
}

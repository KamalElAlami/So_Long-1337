/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:42 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/18 00:07:21 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

void	parse_map(char **map)
{
	if (check_collectibles(map) < 1)
		ft_perror("there is no collectibles");
	if (check_player(map) < 1 || check_player(map) > 1)
		ft_perror("there is no player or there are several players in the map");
	if (check_exit(map) < 1 || check_exit(map) > 1)
		ft_perror("there is no exit or there is several exits in the map");
	if (is_rectangular(map) == 1)
		ft_perror("map is not rectangular");
	if (check_walls(map) == 1)
		ft_perror("map is not serrounded by walls");
	if (check_elements(map) == 1)
		ft_perror("there is a strange element other than P E C 1 0");
}

void	check_path(char *path)
{
	int	i;

	i = 0;
	if (!path)
		ft_perror("map path is not valid or there is no map");
	while (path[i])
	{
		if (path[i] == '.')
		{
			if (ft_strcmp(path + i, ".ber"))
				ft_perror("invalid map extension");
		}
		i++;
	}
}

int	check_validity(char **map)
{
	int	i;
	int	j;
	int	r;

	j = 0;
	r = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'R')
				r++;
			i++;
		}
		j++;
	}
	if (!(check_collectibles(map)) && r)
		return (0);
	return (1);
}

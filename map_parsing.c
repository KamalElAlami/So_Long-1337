/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:42 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/21 08:11:04 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

int	parse_map(char **map, char **smap)
{
	if (check_elements(map) == 1)
		ft_perror("Error \nThere is a strange element other than P E C 1 0\n",
			map, smap, NULL);
	if (check_collectibles(map) < 1)
		ft_perror("Error \nThere is no collectibles \n", map, smap, NULL);
	if (check_player(map) < 1 || check_player(map) > 1)
		ft_perror("Error \nThere is no player or there are several players\n",
			map, smap, NULL);
	if (check_exit(map) < 1 || check_exit(map) > 1)
		ft_perror("Error \nThere is no exit or there is several exits\n",
			map, smap, NULL);
	if (is_rectangular(map) == 1)
		ft_perror("Error \nMap is not rectangular\n", map, smap, NULL);
	if (check_walls(map) == 1)
		ft_perror("Error \nMap is not serrounded by walls\n", map, smap, NULL);
	return (0);
}

void	check_path(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		ft_perror("invalid map extension", NULL, NULL, NULL);
	if (path[len - 4] != '.' || path[len - 3] != 'b'
		|| path[len - 2] != 'e' || path[len - 1] != 'r')
		ft_perror("invalid map extension", NULL, NULL, NULL);
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

void	ft_perror(char *msg, char **map, char **smap, char *optional)
{
	ft_printf(RED "%s\n" RESET, msg);
	free_array(map);
	free_array(smap);
	free(optional);
	exit(EXIT_FAILURE);
}

int	check_elements(char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		while ((*map)[i])
		{
			if ((*map)[i] != '1' && (*map)[i] != '0' && (*map)[i] != 'P'
				&& (*map)[i] != 'C' && (*map)[i] != 'E' && (*map)[i] != '\n')
				return (1);
			i++;
		}
		i = 0;
		map++;
	}
	return (0);
}

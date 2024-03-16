/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:22 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/16 00:19:38 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"

void load_graphics(char **map, void *mlx, int width, int height)
{
    int i;
    int j;
    int x = HEIGHT;
    int y = WIDTH;

    j = 0;
    void *mlx_win = mlx_new_window(mlx, (width -1) * 32, height * 32, "lo3ba");
     while (map[j])
        {
            i = 0;
            while (map[j][i])
            {
                void *img = mlx_xpm_file_to_image(mlx, "./assets/grace.xpm",&x, &y);
                mlx_put_image_to_window(mlx, mlx_win, img, i * 32, j * 32);
                if (map[j][i] == '1')
                {
                    void *img = mlx_xpm_file_to_image(mlx, "./assets/stone.xpm",&x, &y);
                    mlx_put_image_to_window(mlx, mlx_win, img, i * 32, j * 32);
                    
                }
                if (map[j][i] == '0')
                {
                    img = mlx_xpm_file_to_image(mlx, "./assets/grace.xpm",&x, &y);
                    mlx_put_image_to_window(mlx, mlx_win, img, i * 32, j * 32);
                }
                if (map[j][i] == 'P')
                {
                    void *img = mlx_xpm_file_to_image(mlx, "./assets/character.xpm",&x, &y);
                    mlx_put_image_to_window(mlx, mlx_win, img, i * 32, j * 32);   
                }
                if (map[j][i] == 'C')
                {
                    void *img = mlx_xpm_file_to_image(mlx, "./assets/collect.xpm",&x, &y);
                    mlx_put_image_to_window(mlx, mlx_win, img, i * 32, j * 32);
                }
                // if (map[j][i] == 'E')
                // {
                    
                // }
                i++;
                
            }
            j++;
            
        }
}
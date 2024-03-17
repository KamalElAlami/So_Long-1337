/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:22 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/17 03:52:15 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/so_long.h"
#include "includes/ft_printf.h"
typedef struct infos{
    char **map;
    void *mlx;
    void *mlx_win;
    t_assets all;
}infos;
void apply(char **map, void *mlx, void *mlx_win,t_assets all);
int KEY_HOOK(int key,infos *info)
{
    int i =0;
    int j = 0;
    t_cord siko;
    siko = get_coordinates(info ->map);
    if (key == 13)
    {
        siko = get_coordinates(info ->map);
        if (info -> map[siko.y -1 ][siko.x] == '0' || info -> map[siko.y -1 ][siko.x] == 'C')
        {
            info -> map[siko.y][siko.x] = '0';
            info -> map[siko.y - 1 ][siko.x] = 'P';
        }
    }   
    else if (key == 0)
    {
        siko = get_coordinates(info -> map);
        if (info -> map[siko.y][siko.x-1] == '0' || info -> map[siko.y][siko.x -1] == 'C')
        {
            info -> map[siko.y][siko.x] = '0';
            info -> map[siko.y][siko.x - 1] = 'P';
        }
    }   
    else if (key == 1)
    {
        siko = get_coordinates(info -> map);
        if (info -> map[siko.y+1][siko.x] == '0' || info -> map[siko.y+1 ][siko.x] == 'C')
        {
            info -> map[siko.y][siko.x] = '0';
            info -> map[siko.y + 1 ][siko.x] = 'P';
        }
    }   
    else if (key == 2)
    {
        siko = get_coordinates(info -> map);
        if (info -> map[siko.y][siko.x + 1] == '0' || info -> map[siko.y][siko.x + 1] == 'C')
        {
            info -> map[siko.y][siko.x] = '0';
            info -> map[siko.y][siko.x + 1] = 'P';
        }
    }
    if(key == 53)
        exit(0);
    apply(info -> map,info -> mlx,info -> mlx_win,info->all);
    return (0);
}
t_assets ass_img(void *mlx)
{
    t_assets all;
        int x = 32;
    int y = 32;
     all.ground_img = mlx_xpm_file_to_image(mlx, "./assets/grace.xpm",&x, &y);
     all.wall_img = mlx_xpm_file_to_image(mlx, "./assets/stone.xpm",&x, &y);
      all.player_img = mlx_xpm_file_to_image(mlx, "./assets/character.xpm",&x, &y);
     all.collect_img = mlx_xpm_file_to_image(mlx, "./assets/collect.xpm",&x, &y);
     all.exit_img = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm",&x, &y);
    return(all);
}
void destroy_imgs(void *mlx,t_assets all)
{
	mlx_destroy_image(mlx,all.collect_img);
    mlx_destroy_image(mlx,all.exit_img );
    mlx_destroy_image(mlx,all.ground_img );
    mlx_destroy_image(mlx,all.player_img );
    mlx_destroy_image(mlx,all.wall_img);
}
void apply(char **map, void *mlx, void *mlx_win,t_assets all)
{
    int i;
    int j;
    int x = 32;
    int y = 32;
    j = 0;
    static int m;
    if(m)
    {
        destroy_imgs(mlx,all);
        m =1;
    }
    printf("hello\n");
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
void load_graphics(char **map, void *mlx, int width, int height)
{Œ
    void *mlx_win = mlx_new_window(mlx, (width -1) * 32, height * 32, "lo3ba");
    t_assets all = ass_img(mlx);
    apply(map,mlx,mlx_win,all);
    infos op;
    op.map = map;
    op.mlx = mlx;
    op.mlx_win = mlx_win;
    op.all = all;
    int k = mlx_hook(mlx_win, 2, 0, KEY_HOOK, &op);
        mlx_loop(mlx);
}

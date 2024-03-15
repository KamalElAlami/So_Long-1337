#include <mlx.h>

int main()
{
    void *mlx = mlx_init();
    void *mlx_win = mlx_new_window(mlx,806, 1074, "lo3ba");
    int x = 403;
    int y =537;
    void *img = mlx_xpm_file_to_image(mlx, "download.xpm",&x, &y);
    mlx_put_image_to_window(mlx, mlx_win, img,100, 100);
    mlx_loop(mlx);
}
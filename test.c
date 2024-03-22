#include <mlx.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define ENEMY_SIZE 20
#define ENEMY_SPEED 2

typedef struct {
    int x;
    int y;
    int direction;
} Enemy;

int moveEnemy(void *param) {
    void **params = (void **)param;
    void *mlx = params[0];
    void *window = params[1];
    Enemy *enemy = (Enemy *)params[2];

    mlx_clear_window(mlx, window);

    if (enemy->direction == 1) {
        enemy->x += ENEMY_SPEED;
        if (enemy->x >= WIN_WIDTH - ENEMY_SIZE)
            enemy->direction = -1;
    } else {
        enemy->x -= ENEMY_SPEED;
        if (enemy->x <= 0)
            enemy->direction = 1;
    }

    mlx_pixel_put(mlx, window, enemy->x, enemy->y, 0xFFFFFF);

    return 0;
}

int main() {
    void *mlx;
    void *window;
    Enemy enemy;
    void *params[3];

    mlx = mlx_init();
    window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Enemy Patrolling");

    enemy.x = WIN_WIDTH / 2 - ENEMY_SIZE / 2;
    enemy.y = WIN_HEIGHT / 2 - ENEMY_SIZE / 2;
    enemy.direction = 1;

    params[0] = mlx;
    params[1] = window;
    params[2] = &enemy;

    mlx_loop_hook(mlx, moveEnemy, params);

    mlx_loop(mlx);

    return 0;
}
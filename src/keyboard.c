#include "wolf.h"
#include "keys.h"
#include <stdlib.h>
#include <math.h>

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_LEFT)
		rotate_player(&mlx->player, -2.0f / 180.0f * M_PI);
	if (key == K_RIGHT)
		rotate_player(&mlx->player, 2.0f / 180.0f * M_PI);
	if (key == K_UP)
		move_player(&mlx->player, mlx->map, 0.05f);
	if (key == K_DOWN)
		move_player(&mlx->player, mlx->map, -0.05f);
	render(mlx);
	return (0);
}

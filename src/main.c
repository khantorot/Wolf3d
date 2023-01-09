#include "libft.h"
#include "mlx.h"
#include "wolf.h"
#include <stdlib.h>

static int	die(char *reason)
{
	ft_putendl(reason);
	exit(EXIT_FAILURE);
	return (1);
}

static int	hook_close(t_mlx *mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_map		*map;

	if (argc < 2)
		return (die("error: not enough arguments\nusage: ./wolf3d [mapfile]"));
	if ((mlx = init()) == NULL)
		return (die("error: mlx couldn't initialize properly"));
	if (load_textures(mlx))
		return (die("error: couldn't load textures"));
	if ((map = read_map(argv[1], mlx->max_tex)) == NULL)
		return (die("error: invalid map file"));
	mlx->map = map;
	init_player(&mlx->player, mlx->map);
	render(mlx);
	mlx_hook(mlx->window, 2, 1L << 0, hook_keydown, mlx);
	mlx_hook(mlx->window, 17, 1L << 0, hook_close, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

#include "../include/ray_casting_bonus.h"

void	ray_casting(t_global *data)
{
	mlx_hook(data->mlx_win, 2, 1, ft_key, data);
	mlx_hook(data->mlx_win, 17, 1, ft_destroy_win, data);
	mlx_hook(data->mlx_win, 6, (1L << 6), ft_mouse, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
}

#include "ray_casting.h"

void ray_casting(t_global *data)
{
	/*
  mlx_hook(data->mlx_win, 17, (1L<<0), destroy_win, data);
  mlx_hook(data->mlx_win, 2, (1L<<0) , ft_key, data);
  mlx_hook(data->mlx_win, 6, (1L<<6) , ft_exit_mouse, data);
  mlx_hook(data->mlx_win, 4, (1L<<2) , ft_mouse_ev, data);
  */
  mlx_loop(data->mlx);
}

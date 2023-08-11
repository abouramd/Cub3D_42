#include "../include/ray_casting.h"

int	ft_loop(t_global *data)
{
	if (data->event)
	{
		send_rays(data);
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
		data->event = false;
	}
	return (0);
}

int	ft_destroy_win(t_global *data)
{
	(void) data;
	exit(0);
	return (1);
}

int	ft_key(int key, t_global *data)
{
	if (key == KEY_ENTER)
		data->start = true;
	if (key == KEY_ECH)
		ft_destroy_win(data);
	if (!data->start)
		return (0);
	if (key == KEY_W)
		ft_move(data, data->angle_of_view);
	if (key == KEY_S)
		ft_move(data, data->angle_of_view + M_PI);
	if (key == KEY_A)
		ft_move(data, data->angle_of_view + M_PI_2);
	if (key == KEY_D)
		ft_move(data, data->angle_of_view - M_PI_2);
	if (key == KEY_LEFT)
		data->angle_of_view += ROTAT_ANG;
	if (key == KEY_RIGHT)
		data->angle_of_view -= ROTAT_ANG;
	data->angle_of_view = norm_angle(data->angle_of_view);
	data->event = true;
	return (0);
}

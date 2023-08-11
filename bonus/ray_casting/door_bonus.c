#include "../include/ray_casting_bonus.h"

void	open_door(t_global *data, t_dda *dda)
{
	data->x_d = -1;
	data->y_d = -1;
	dda_setup(dda);
	ver_dda(data, dda);
	hor_dda(data, dda);
	choose_ver_hor(data, dda, 0);
	if (data->map[(int)data->player_y / CUB_SIZE][(int)data->player_x
		/ CUB_SIZE] == 'D')
	{
		dda->x_d = data->player_x / CUB_SIZE;
		dda->y_d = data->player_y / CUB_SIZE;
		data->x_d = dda->x_d;
		data->y_d = dda->y_d;
	}
	else if (dda->door && dda->dis < 2 * CUB_SIZE)
	{
		data->x_d = dda->x_d;
		data->y_d = dda->y_d;
	}
	else
	{
		dda->x_d = -1;
		dda->y_d = -1;
	}
}

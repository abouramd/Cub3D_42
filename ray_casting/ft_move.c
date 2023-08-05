#include "../include/ray_casting.h"

bool ft_check_hit(char c)
{
	if (c == '1')
		return (true);
	return (false);
}

void	move_player(t_global *data, double ang, double *x, double *y)
{
	int		sx;
	int		sy;
	double	co;
	double	si;

	co = cos(ang);
	si = sin(ang) * -1;
	(*x) += co * 3;
	(*y) += si * 3;
	sx = -1;
 	while (++sx < P_STEP)
	{
		if (ft_check_hit(data->map[(int)(*y) / CUB_SIZE][(int)(*x) / CUB_SIZE]))
			break;
		(*x) += co;
	}
	sy = -1;
	while (++sy < P_STEP)
	{
		if (ft_check_hit(data->map[(int)(*y) / CUB_SIZE][(int)data->player_x / CUB_SIZE]))
			break;
		(*y) += si;
	}
	(*x) -= co * 3;
	(*y) -= si * 3;
}

void	ft_move(t_global *data, double ang)
{
	double x;
	double y;

	x = data->player_x;
	y = data->player_y;
	move_player(data, ang, &x, &y);
	if (!ft_check_hit(data->map[(int)y / CUB_SIZE][(int)data->player_x / CUB_SIZE]))
	{
		data->player_x = x;
		data->player_y = y;
	}
	else if (fabs(data->player_x - x) > fabs(data->player_y - y))
		data->player_x = x;
	else
		data->player_y = y;
}
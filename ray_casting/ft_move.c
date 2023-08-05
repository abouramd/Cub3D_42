#include "../include/ray_casting.h"
#include <stdio.h>

bool	hit(char c)
{
	if (c == '1')
		return (true);
	return (false);
}

int ft_check_sign(double num)
{
	if (num == 0)
		return (0);
	if (num > 0)
		return (1);
	return (-1);
}

void	move_player(t_global *data, double ang, double *x, double *y)
{
	int	sx;
	int	sy;
	double	co;
	double	si;

	co = cos(ang);
	si = sin(ang) * -1;
	(*x) += ft_check_sign(co) * 3;
	(*y) += ft_check_sign(si) * 3;
	sx = -1;
	while (++sx < P_STEP)
	{
<<<<<<< HEAD
		if (ft_check_hit(data->map[(int)(data->player_y) / CUB_SIZE][(int)(*x) / CUB_SIZE]))
			break;
=======
		if (hit(data->map[(int)(*y) / CUB_SIZE][(int)(*x) / CUB_SIZE]))
			break ;
>>>>>>> e23722cb2cf870a331f77371001dcd991f9d84b4
		(*x) += co;
	}
	sy = -1;
	while (++sy < P_STEP)
	{
<<<<<<< HEAD
		if (ft_check_hit(data->map[(int)(*y) / CUB_SIZE][(int)(data->player_x) / CUB_SIZE]))
			break;
=======
		if (hit(data->map[(int)(*y) / CUB_SIZE][(int)data->player_x / CUB_SIZE]))
			break ;
>>>>>>> e23722cb2cf870a331f77371001dcd991f9d84b4
		(*y) += si;
	}
	(*x) -= ft_check_sign(co) * 3;
	(*y) -= ft_check_sign(si) * 3;
}

void	ft_move(t_global *data, double ang)
{
	double	x;
	double	y;

	x = data->player_x;
	y = data->player_y;
	move_player(data, ang, &x, &y);
<<<<<<< HEAD
	if (!ft_check_hit(data->map[(int)y / CUB_SIZE][(int)x / CUB_SIZE]))
=======
	if (!hit(data->map[(int)y / CUB_SIZE][(int)data->player_x / CUB_SIZE]))
>>>>>>> e23722cb2cf870a331f77371001dcd991f9d84b4
	{
		data->player_x = x;
		data->player_y = y;
	}
	else if (fabs(data->player_x - x))
	{
		printf("1 => hello x %f - %f\n", data->player_x, x);
		data->player_x = x;
	}
	else if (fabs(data->player_y - y))
	{
		printf("2 => hello y\n");
		data->player_y = y;
<<<<<<< HEAD
	}
=======
>>>>>>> e23722cb2cf870a331f77371001dcd991f9d84b4
}

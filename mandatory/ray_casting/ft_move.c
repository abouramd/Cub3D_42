#include "../include/ray_casting.h"
#include <stdio.h>

bool	ft_check_hit(char c)
{
	if (c == '1')
		return (true);
	return (false);
}

int	ft_check_sign(double num)
{
	if (num == 0)
		return (0);
	if (num > 0)
		return (1);
	return (-1);
}

// void	add_or_sub(double *x, double *y, double co, double si, char c)
// {
// 	if (c == '+')
// 	{
// 		(*x) += ft_check_sign(co) * 6;
// 		(*y) += ft_check_sign(si) * 6;
// 	}
// 	else
// 	{
// 		(*x) -= ft_check_sign(co) * 6;
// 		(*y) -= ft_check_sign(si) * 6;
// 	}
// }

void	move_player(t_global *data, double ang, double *x, double *y)
{
	int		sx;
	int		sy;
	double	co;
	double	si;

	co = cos(ang);
	si = sin(ang) * -1;
	add_at_start(x, y, co, si);
	sx = -1;
	while (++sx < P_STEP)
	{
		if (ft_check_hit(data->map[(int)(data->player_y) / CUB_SIZE]
			[(int)(*x) / CUB_SIZE]))
			break ;
		(*x) += co;
	}
	sy = -1;
	while (++sy < P_STEP)
	{
		if (ft_check_hit(data->map[(int)(*y) / CUB_SIZE]
			[(int)(data->player_x) / CUB_SIZE]))
			break ;
		(*y) += si;
	}
	sub_at_end(x, y, co, si);
}

void	ft_move(t_global *data, double ang)
{
	double	x;
	double	y;

	x = data->player_x;
	y = data->player_y;
	move_player(data, ang, &x, &y);
	if (!ft_check_hit(data->map[(int)y / CUB_SIZE][(int)x / CUB_SIZE]))
	{
		data->player_x = x;
		data->player_y = y;
	}
	else if (fabs(data->player_x - x))
		data->player_x = x;
	else if (fabs(data->player_y - y))
		data->player_y = y;
}

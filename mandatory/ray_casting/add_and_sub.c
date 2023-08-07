#include "../include/ray_casting.h"

void	add_at_start(double *x, double *y, double co, double si)
{
	(*x) += ft_check_sign(co) * 6;
	(*y) += ft_check_sign(si) * 6;
}

void	sub_at_end(double *x, double *y, double co, double si)
{
	(*x) -= ft_check_sign(co) * 6;
	(*y) -= ft_check_sign(si) * 6;
}

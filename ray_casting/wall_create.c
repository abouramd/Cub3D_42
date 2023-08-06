#include "../include/ray_casting.h"

// double  get_hight(t_dda *dda)
// {
// 	double  real_distance;
// 	double  hight;

// 	real_distance = (W_WIDTH / 2) * (tan(30 * M_PI / 180));
// 	hight = (real_distance * CUB_SIZE) / dda->dis;
// 	return (hight);
// }

void    fill_from_until(double *from, double *until, double wall_hight)
{
	(*from) = W_HEIGTH / 2 - wall_hight / 2;
	(*until) = W_HEIGTH / 2 + wall_hight / 2;
	// if ((*from) < 0)
	// 	(*from) = 0;
	// if (((*until) > W_HEIGTH))
	// 	(*from) = W_HEIGTH;
}

void    fake_3d(t_global *data, t_dda *dda, double from, double until, int nb_rays)
{
	int i;

	i = 0;
	while (i <= from)
	{
		my_mlx_pixel_put(&data->img, nb_rays, i, BLUE);
		i++;
	}
	while (from <= until && from < W_HEIGTH)
	{
		my_mlx_pixel_put(&data->img, nb_rays, from, dda->color);
		from++;
	}
	while(until < W_HEIGTH)
	{
		my_mlx_pixel_put(&data->img, nb_rays, until, GREEN);
		until++;
	}
}

void	create_walls(t_global *data, t_dda *dda, int nb_rays)
{
	double  wall_hight;
	double  from;
	double  until;

	wall_hight = dda->wall_hiegth;
	fill_from_until(&from, &until, wall_hight);
	fake_3d(data, dda, from, until, nb_rays);
}
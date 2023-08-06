#include "../include/ray_casting.h"

void	fill_from_until(t_dda *dda)
{
	dda->from = W_HEIGTH / 2 - dda->wall_hiegth / 2;
	dda->until = W_HEIGTH / 2 + dda->wall_hiegth / 2;
}

void	fake_3d(t_global *data, t_dda *dda, int nb_rays)
{
	dda->i = 0;
	while (dda->i < dda->from)
	{
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, BLUE);
		dda->i++;
	}
	while (dda->i < dda->until && dda->i < W_HEIGTH)
	{
		dda->color = drwaframe(dda);
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, dda->color);
		dda->i++;
	}
	while (dda->i < W_HEIGTH)
	{
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, GREEN);
		dda->i++;
	}
}

void	create_walls(t_global *data, t_dda *dda, int nb_rays)
{
	fill_from_until(dda);
	fake_3d(data, dda, nb_rays);
}

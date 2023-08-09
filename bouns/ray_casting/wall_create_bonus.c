#include "../include/ray_casting_bonus.h"

void	fill_from_until(t_dda *dda)
{
	dda->from = W_HEIGHT / 2 - dda->wall_height / 2;
	dda->until = W_HEIGHT / 2 + dda->wall_height / 2;
}

void	fake_3d(t_global *data, t_dda *dda, int nb_rays)
{
	dda->i = 0;
	while (dda->i < dda->from)
	{
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, data->ceil);
		dda->i++;
	}
	while (dda->i < dda->until && dda->i < W_HEIGHT)
	{
		dda->color = drwaframe(dda);
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, dda->color);
		dda->i++;
	}
	while (dda->i < W_HEIGHT)
	{
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, data->floor);
		dda->i++;
	}
}

void	create_walls(t_global *data, t_dda *dda, int nb_rays)
{
	double	wall_hit;
	
	wall_hit = dda->x_hit + dda->y_hit;
	wall_hit = wall_hit - CUB_SIZE * (int)(wall_hit / CUB_SIZE);
	dda->x_c = wall_hit / CUB_SIZE * dda->img->width;
	dda->x_s = wall_hit / CUB_SIZE * dda->an->a[dda->an->af].width;	
	fill_from_until(dda);
	fake_3d(data, dda, nb_rays);
}

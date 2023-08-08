#include "../include/ray_casting.h"

void	choose_ver_hor(t_global *data, t_dda *dda, double ang)
{
	if (dda->dis_v >= dda->dis_h)
	{
		dda->dis = dda->dis_h;
		dda->x_hit = dda->x_hit_h;
		dda->y_hit = dda->y_hit_h;
		if (dda->dir_y == -1)
			dda->img = &data->no;
		else
			dda->img = &data->so;
	}
	else
	{
		dda->dis = dda->dis_v;
		dda->x_hit = dda->x_hit_v;
		dda->y_hit = dda->y_hit_v;
		if (dda->dir_x == -1)
			dda->img = &data->we;
		else
			dda->img = &data->ea;
	}
	dda->dis *= cos(ang);
	dda->wall_hiegth = CUB_SIZE * W_HEIGTH / dda->dis;
}

void	send_rays(t_global *data)
{
	t_dda	dda;
	int		count_rays;
	double	val;

	count_rays = 0;
	val = (30 * M_PI / 180);
	dda.ang = data->angle_of_view + val;
	val /= W_WIDTH / 2;
	while (count_rays < W_WIDTH)
	{
		dda_setup(&dda);
		ver_dda(data, &dda);
		hor_dda(data, &dda);
		choose_ver_hor(data, &dda, dda.ang - data->angle_of_view);
		create_walls(data, &dda, count_rays);
		count_rays++;
		dda.ang -= val;
	}
}

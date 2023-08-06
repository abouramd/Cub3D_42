#include "../include/ray_casting.h"

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0)
		return (0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

unsigned int	drwaframe(t_dda *dda)
{
	double	alpha;
	double	y_c;
	double	wall_hit;
	double	x_c;

	alpha = dda->i - dda->from;
	y_c = (alpha / dda->wall_hiegth) * dda->img->heigth;
	wall_hit = dda->x_hit + dda->y_hit;
	wall_hit = wall_hit - CUB_SIZE * (int)(wall_hit / CUB_SIZE);
	x_c = wall_hit / CUB_SIZE * dda->img->width;
	return (my_mlx_pixel_get(dda->img, x_c, y_c));
}

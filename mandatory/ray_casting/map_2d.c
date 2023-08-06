#include "../include/ray_casting.h"

void ft_draw_dir(t_data *data, double x, double y, double ang)
{
	double si = sin(ang) * -1;
	double co = cos(ang);
	int count = 15;

	while (count--)
	{
		my_mlx_pixel_put(data, x, y, YELLOW);
		x += co;
		y += si;
	}
}

void	ft_draw_player(t_data *img, size_t xc, size_t yc, int radius)
{
	int   err;
	int   color;
	int   x;
	int   y;  
	if (radius < 0)
		return;
	ft_draw_player(img, xc, yc, radius - 1);
	color = WHITE;
	x = -radius;
	y = 0;
	err = 2 - 2 * radius;
	while (x < 0)
	{
		my_mlx_pixel_put(img, xc - x, yc + y, color);
		my_mlx_pixel_put(img, xc - y, yc - x, color);
		my_mlx_pixel_put(img, xc + x, yc - y, color);
		my_mlx_pixel_put(img, xc + y, yc + x, color);
		radius = err;
		if (radius <= y)
			err += ++y * 2 + 1;
		if (radius > x || err > y)
			err += ++x * 2 + 1;
	}
}

void    map_2d(t_global *data)
{
		int i;
		int j;

		i = 0;
		j = 0;
		while (j < data->hiegth * CUB_SIZE)
		{
				i = 0;
				while (i < data->width * CUB_SIZE)
				{
						if (j % CUB_SIZE == 0 || i % CUB_SIZE == 0)
								my_mlx_pixel_put(&data->img, i, j, WHITE);
						else if (data->map[j / CUB_SIZE][i / CUB_SIZE] == '1')
								my_mlx_pixel_put(&data->img, i, j, RED);
						else
								my_mlx_pixel_put(&data->img, i, j, BLACK);
						i++;
				}
				j++;
		}
		ft_draw_player(&data->img, data->player_x, data->player_y, 5);
		ft_draw_dir(&data->img, data->player_x, data->player_y, data->angle_of_view);
}

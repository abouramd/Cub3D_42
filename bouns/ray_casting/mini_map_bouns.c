#include "../include/ray_casting_bouns.h"

#define MINI_WIDTH (W_WIDTH / 5)
#define MINI_HEIGTH (W_HEIGTH / 5)
#define MINI_CUBE 20

void setup_mini_map(t_global *data, t_dda *dda, t_mini *mini)
{
	mini->x = (MINI_CUBE * data->player_x) / CUB_SIZE - MINI_WIDTH / 2;
	mini->y = (MINI_CUBE * data->player_y) / CUB_SIZE - MINI_HEIGTH / 2;
	mini->x_start = 0;
	mini->y_start = 0;
	mini->map = data->map;
	mini->angle = data->angle_of_view; 
	mini->width = data->width * MINI_CUBE;
	mini->heigth = data->hiegth * MINI_CUBE;
	mini->img = &data->img;
}

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

void draw_map(t_mini *mini, int x, int y)
{
	if (mini->x_start >= W_WIDTH || mini->y_start >= W_HEIGTH)
		return ;
	if (x < 0 || y < 0 || x >= mini->width || y >= mini->heigth)
		my_mlx_pixel_put(mini->img, mini->x_start, mini->y_start, BLACK);
	else if (mini->map[(int)y / MINI_CUBE][(int)x / MINI_CUBE] == '1')
		my_mlx_pixel_put(mini->img, mini->x_start, mini->y_start, RED);
	else if (mini->map[(int)y / MINI_CUBE][(int)x / MINI_CUBE] == 'D')
		my_mlx_pixel_put(mini->img, mini->x_start, mini->y_start, YELLOW);
	else if (mini->map[(int)y / MINI_CUBE][(int)x / MINI_CUBE] == '0')
		my_mlx_pixel_put(mini->img, mini->x_start, mini->y_start, CYAN);
	else
		my_mlx_pixel_put(mini->img, mini->x_start, mini->y_start, BLACK);
}

void mini_map(t_mini *mini)
{
	while (mini->y_start < MINI_HEIGTH )
	{
		mini->x_start = 0;
		while (mini->x_start < MINI_WIDTH)
		{
			draw_map(mini, mini->x + mini->x_start, mini->y + mini->y_start);
			mini->x_start++;
		}
		mini->y_start++;
	}
	ft_draw_player(mini->img, MINI_WIDTH / 2, MINI_HEIGTH / 2, 5);
	ft_draw_dir(mini->img, MINI_WIDTH / 2, MINI_HEIGTH / 2, mini->angle);
}



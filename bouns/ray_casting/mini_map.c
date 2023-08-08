#include "../include/ray_casting_bouns.h"

#define MINI_WIDTH W_WIDTH
#define MINI_HEIGTH W_HEIGTH
#define MINI_CUBE 10

void setup_mini_map(t_global *data, t_dda *dda, t_mini *mini)
{
	mini->x = (MINI_CUBE * data->player_x) / CUB_SIZE;
	mini->y = (MINI_CUBE * data->player_y) / CUB_SIZE;
	mini->x_start = 0;
	mini->y_start = 0;
	mini->map = data->map;
	mini->angle = data->angle_of_view; 
	mini->width = data->width * MINI_CUBE;
	mini->heigth = data->hiegth * MINI_CUBE;
	mini->img = &data->img;
}


void draw_map(t_mini *mini, int x, int y)
{
	if (x < 0 || y < 0)
		my_mlx_pixel_put(t_data *data, int x, int y, int color)	
}


void mini_map(t_mini *mini)
{
	while ()
}

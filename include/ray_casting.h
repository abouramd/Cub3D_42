#ifndef RAY_CASTING_H
#define RAY_CASTING_H

#include "cub.h"
#include <wchar.h>

typedef struct s_dda
{
	double	wall_hiegth;
	double	x_hit;
	double	y_hit;
	double	dis;
	double	x_hit_h;
	double	y_hit_h;
	double	dis_h;
	double	x_hit_v;
	double	y_hit_v;
	double	dis_v;
	double	ang;
	double	tan;
	double	si;
	double	co;
	double	dir_x;
	double	dir_y;
	int color;
}			t_dda;

int		ft_loop(t_global *data);
void	map_2d(t_global *data);
int		ft_destroy_win(t_global *data);
int		ft_key(int key, t_global* data);
void	ft_move(t_global *data, double ang);

/* dda */
void	hor_dda(t_global *data, t_dda *dda);
void	ver_dda(t_global *data, t_dda *dda);

void	send_rays(t_global *data);

void	dda_setup(t_dda *dda);

void	create_walls(t_global *data, t_dda *dda, int nb_rays);

#endif // !RAY_CASTING_H

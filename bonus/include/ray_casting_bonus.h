#ifndef RAY_CASTING_BONUS_H
# define RAY_CASTING_BONUS_H

# include "cub_bonus.h"

typedef struct s_dda
{
	double		wall_height;
	double		x_hit;
	double		y_hit;
	double		dis;
	int			x_d;
	int			y_d;
	bool		door;
	double		x_hit_h;
	double		y_hit_h;
	double		dis_h;
	int			x_d_h;
	int			y_d_h;
	bool		door_h;
	double		x_hit_v;
	double		y_hit_v;
	double		dis_v;
	int			x_d_v;
	int			y_d_v;
	bool		door_v;
	double		ang;
	double		tan;
	double		si;
	double		co;
	double		dir_x;
	double		dir_y;
	int			color;
	double		from;
	double		until;
	int			i;
	t_anim		*an;
	t_data		*img;
	int			x_c;
	int			y_c;
	int			x_s;
	int			y_s;
}				t_dda;

typedef struct s_mini
{
	int			x;
	int			y;
	int			x_start;
	int			y_start;
	int			width;
	int			height;
	double		angle;
	char		**map;
	t_data		*img;
	int			x_d;
	int			y_d;
}				t_mini;

void			ft_move(t_global *data, double ang);

/* dda */
void			dda_setup(t_dda *dda);
void			hor_dda(t_global *data, t_dda *dda);
void			ver_dda(t_global *data, t_dda *dda);

void			send_rays(t_global *data);

int				ft_key(int key, t_global *data);
int				ft_mouse(int x, int y, t_global *data);
int				ft_destroy_win(t_global *data);
int				ft_loop(t_global *data);

void			create_walls(t_global *data, t_dda *dda, int nb_rays);
unsigned int	drwaframe(t_dda *dda);

void			controle_spirt(t_global *data, int *timer);

int				ft_check_sign(double num);

void			setup_mini_map(t_global *data, t_dda *dda, t_mini *mini);

void			mini_map(t_mini *mini);

void			choose_ver_hor(t_global *data, t_dda *dda, double ang);

void			open_door(t_global *data, t_dda *dda);

#endif // !RAY_CASTING_H

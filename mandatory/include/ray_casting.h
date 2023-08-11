/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:05:37 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:05:38 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "cub.h"
# include <wchar.h>

typedef struct s_dda
{
	double		wall_hiegth;
	double		x_hit;
	double		y_hit;
	double		dis;
	double		x_hit_h;
	double		y_hit_h;
	double		dis_h;
	double		x_hit_v;
	double		y_hit_v;
	double		dis_v;
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
	t_data		*img;
}				t_dda;

int				ft_loop(t_global *data);
void			map_2d(t_global *data);
int				ft_destroy_win(t_global *data);
int				ft_key(int key, t_global *data);
void			ft_move(t_global *data, double ang);
/* dda */
void			hor_dda(t_global *data, t_dda *dda);
void			ver_dda(t_global *data, t_dda *dda);
void			send_rays(t_global *data);
void			dda_setup(t_dda *dda);
void			create_walls(t_global *data, t_dda *dda, int nb_rays);
unsigned int	drwaframe(t_dda *dda);
void			add_at_start(double *x, double *y, double co, double si);
void			sub_at_end(double *x, double *y, double co, double si);
int				ft_check_sign(double num);
double			norm_angle(double angle);

#endif // !RAY_CASTING_H

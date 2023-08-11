/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:06:44 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:06:45 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting_bonus.h"

void	pick_hor(t_global *data, t_dda *dda)
{
	dda->door = dda->door_h;
	dda->x_d = dda->x_d_h;
	dda->y_d = dda->y_d_h;
	dda->dis = dda->dis_h;
	dda->x_hit = dda->x_hit_h;
	dda->y_hit = dda->y_hit_h;
	if (dda->dir_y == -1)
		dda->img = &data->no;
	else
		dda->img = &data->so;
}

void	pick_ver(t_global *data, t_dda *dda)
{
	dda->door = dda->door_v;
	dda->x_d = dda->x_d_v;
	dda->y_d = dda->y_d_v;
	dda->dis = dda->dis_v;
	dda->x_hit = dda->x_hit_v;
	dda->y_hit = dda->y_hit_v;
	if (dda->dir_x == -1)
		dda->img = &data->we;
	else
		dda->img = &data->ea;
}

void	choose_ver_hor(t_global *data, t_dda *dda, double ang)
{
	if (dda->dis_v >= dda->dis_h)
		pick_hor(data, dda);
	else
		pick_ver(data, dda);
	if (dda->door)
		dda->img = &data->door;
	dda->dis *= cos(ang);
	dda->wall_height = CUB_SIZE * W_HEIGHT / dda->dis;
}

void	send_rays(t_global *data)
{
	t_mini	mini;
	t_dda	dda;
	int		count_rays;
	double	val;

	count_rays = 0;
	val = (30 * M_PI / 180);
	dda.ang = data->angle_of_view;
	dda.an = &data->anim;
	data->dda = &dda;
	open_door(data, &dda);
	setup_mini_map(data, &dda, &mini);
	dda.ang += val;
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
	mini_map(&mini);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_create_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:15:09 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:15:10 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting_bonus.h"

void	fill_from_until(t_dda *dda)
{
	dda->from = (float)W_HEIGHT / 2 - dda->wall_height / 2;
	dda->until = (float)W_HEIGHT / 2 + dda->wall_height / 2;
}

unsigned int	dark_rgb(unsigned int rgb, int range)
{
	int	r;
	int	g;
	int	b;

	r = ((rgb >> 16) & 255);
	g = ((rgb >> 8) & 255);
	b = (rgb & 255);
	r -= range;
	g -= range;
	b -= range;
	if (r < 0 || r > 255)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	fake_3d(t_global *data, t_dda *dda, int nb_rays)
{
	double	range;
	double	inc;

	range = 0;
	inc = 255 / ((double)W_HEIGHT / 2);
	dda->i = 0;
	while (dda->i++ <= dda->from)
	{
		dda->color = dark_rgb(data->ceil, range);
		my_mlx_pixel_put(&data->img, nb_rays, dda->i - 1, dda->color);
		range += inc;
	}
	while (dda->i < dda->until && dda->i < W_HEIGHT)
	{
		dda->color = drwaframe(dda);
		dda->color = dark_rgb(dda->color, dda->dis / 4);
		my_mlx_pixel_put(&data->img, nb_rays, dda->i, dda->color);
		dda->i++;
	}
	while (dda->i++ < W_HEIGHT)
	{
		dda->color = dark_rgb(data->floor, range);
		my_mlx_pixel_put(&data->img, nb_rays, dda->i - 1, dda->color);
		range -= inc;
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

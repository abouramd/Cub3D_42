/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawframe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:06:05 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:06:06 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting_bonus.h"

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
	unsigned int	co;
	double			alpha;

	alpha = dda->i - dda->from;
	dda->y_c = (alpha / dda->wall_height) * dda->img->height;
	dda->y_s = (alpha / dda->wall_height) * dda->an->a[dda->an->af].height;
	co = my_mlx_pixel_get(&dda->an->a[dda->an->af], dda->x_s, dda->y_s);
	if (!dda->door && !(co >> 24))
		return (co);
	return (my_mlx_pixel_get(dda->img, dda->x_c, dda->y_c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:10:05 by abouramd          #+#    #+#             */
/*   Updated: 2023/08/11 10:10:06 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars.h"

int	create_rgb(int *p)
{
	return (0 << 24 | p[0] << 16 | p[1] << 8 | p[2]);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_creat_texters(t_global *f, t_pars *ptr)
{
	(void)f;
	(void)ptr;
	f->no.addr = mlx_get_data_addr(f->no.img, &f->no.bits_per_pixel,
			&f->no.line_length, &f->no.endian);
	if (f->no.img == NULL)
		return (put_err("NO", strerror(errno)), -1);
	f->so.addr = mlx_get_data_addr(f->so.img, &f->so.bits_per_pixel,
			&f->so.line_length, &f->so.endian);
	if (f->so.img == NULL)
		return (put_err("SO", strerror(errno)), -1);
	f->we.addr = mlx_get_data_addr(f->we.img, &f->we.bits_per_pixel,
			&f->we.line_length, &f->we.endian);
	if (f->we.img == NULL)
		return (put_err("WE", strerror(errno)), -1);
	f->ea.addr = mlx_get_data_addr(f->ea.img, &f->ea.bits_per_pixel,
			&f->ea.line_length, &f->ea.endian);
	if (f->ea.img == NULL)
		return (put_err("EA", strerror(errno)), -1);
	return (0);
}

int	ft_creat_image(t_global *f, t_pars *ptr)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (put_err("mlx_init", strerror(errno)), -1);
	f->no.img = mlx_xpm_file_to_image(f->mlx, ptr->no,
			&f->no.width, &f->no.heigth);
	if (f->no.img == NULL)
		return (put_err("NO", strerror(errno)), -1);
	f->so.img = mlx_xpm_file_to_image(f->mlx, ptr->so,
			&f->so.width, &f->so.heigth);
	if (f->so.img == NULL)
		return (put_err("SO", strerror(errno)), -1);
	f->we.img = mlx_xpm_file_to_image(f->mlx, ptr->we,
			&f->we.width, &f->we.heigth);
	if (f->we.img == NULL)
		return (put_err("WE", strerror(errno)), -1);
	f->ea.img = mlx_xpm_file_to_image(f->mlx, ptr->ea,
			&f->ea.width, &f->ea.heigth);
	if (f->ea.img == NULL)
		return (put_err("EA", strerror(errno)), -1);
	return (0);
}

int	fill_data(t_global *f, t_pars *ptr)
{
	int i;

	if (ft_creat_image(f, ptr) == -1)
		return (-1);
	if (ft_creat_texters(f, ptr) == -1)
		return (-1);
	i = 0;
	while (ptr->map[i] && !ptr->map[i][skip_white_space(ptr->map[i], 0)])
		i++;
	while (ptr->map[i] && ptr->map[i][skip_white_space(ptr->map[i], 0)])
		i++;
	while (ptr->map[i] && !ptr->map[i][skip_white_space(ptr->map[i], 0)])
		i++;
	if (ptr->map[i])
		return (put_err("map", "empty line in the map"), -1);
	f->map = ptr->map;
	ptr->map = NULL;
	f->player_x = ptr->player_x;
	f->player_y = ptr->player_y;
	f->floor = create_rgb(ptr->floor);
	f->ciel = create_rgb(ptr->ciel);
	f->field_of_view = ptr->field_of_view;
	return (0);
}

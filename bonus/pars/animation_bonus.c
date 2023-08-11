/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:04:33 by abouramd          #+#    #+#             */
/*   Updated: 2023/08/11 10:04:34 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars_bonus.h"

void	join_with_num(char *str, char *first, int num, char *last)
{
	int	i;
	int	n;

	i = 0;
	if (!str)
		return ;
	while (first && *first)
		str[i++] = *(first++);
	n = num;
	if (!n)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	n = i;
	while (num || n == i)
	{
		str[--n] = num % 10 + 48;
		num /= 10;
	}
	while (last && *last)
		str[i++] = *(last++);
	str[i] = 0;
}

int	ft_open_anim(t_global *data, t_data *img, char *path, char *ext)
{
	char	str[500];
	int		i;

	i = 0;
	while (i < MAX_IMG)
	{
		join_with_num(str, path, i, ext);
		img[i].img = mlx_xpm_file_to_image(data->mlx, str, &img[i].width,
				&img[i].height);
		if (!img[i].img)
		{
			if (!i)
				return (perror(str), -1);
			return (0);
		}
		img[i].addr = mlx_get_data_addr(img[i].img, &img[i].bits_per_pixel,
				&img[i].line_length, &img[i].endian);
		if (!img[i].addr)
			break ;
		i++;
	}
	return (0);
}

int	ft_animation_pars(t_global *f)
{
	f->anim.af = 0;
	f->anim.a = ft_calloc(MAX_IMG + 1, sizeof(t_data));
	if (!f->anim.a)
	{
		perror("ft_calloc");
		return (-1);
	}
	return (ft_open_anim(f, f->anim.a, "./images/animation/anim-", ".xpm"));
}

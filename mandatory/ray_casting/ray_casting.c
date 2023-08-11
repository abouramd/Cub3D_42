/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:05:05 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:05:06 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting.h"

void	ray_casting(t_global *data)
{
	mlx_hook(data->mlx_win, 2, 1, ft_key, data);
	mlx_hook(data->mlx_win, 17, 1, ft_destroy_win, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
}

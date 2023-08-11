/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:04:17 by zasabri           #+#    #+#             */
/*   Updated: 2023/08/11 10:04:18 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray_casting.h"

void	add_at_start(double *x, double *y, double co, double si)
{
	(*x) += ft_check_sign(co) * 6;
	(*y) += ft_check_sign(si) * 6;
}

void	sub_at_end(double *x, double *y, double co, double si)
{
	(*x) -= ft_check_sign(co) * 6;
	(*y) -= ft_check_sign(si) * 6;
}

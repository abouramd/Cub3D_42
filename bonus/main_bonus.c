/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:04:28 by abouramd          #+#    #+#             */
/*   Updated: 2023/08/11 10:04:29 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub_bonus.h"

int	main(int ac, char **av)
{
	t_global	d;

	if (pars(&d, ac, av) == -1)
		exit (1);
	ray_casting(&d);
	free_data(&d);
	return (0);
}

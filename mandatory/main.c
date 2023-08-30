/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:10:23 by abouramd          #+#    #+#             */
/*   Updated: 2023/08/11 10:10:24 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	main(int ac, char **av)
{
	t_global	d;

	if (pars(&d, ac, av) == -1)
		exit (1);
	ray_casting(&d);
	free_data(&d);
	return (0);
}

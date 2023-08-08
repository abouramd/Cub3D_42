#include "include/cub.h"

int	main(int ac, char **av)
{
	t_global	d;

	if (pars(&d, ac, av) == -1)
		return (1);
	ray_casting(&d);
	free_data(&d);
	return (0);
}

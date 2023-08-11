#include "../include/ray_casting_bonus.h"
void	controle_spirt(t_global *data, int *timer)
{	
	if (*timer > 1000)
	{
		data->anim.af++;
		if (!data->anim.a[data->anim.af].img
			|| !data->anim.a[data->anim.af].addr)
			data->anim.af = 0;
		data->event = true;
		*timer = 0;
	}
}

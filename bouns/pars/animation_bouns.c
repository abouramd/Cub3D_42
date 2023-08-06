#include "../include/pars_bouns.h"

#define MAX_IMG 200

void join_with_num(char *str, char *first, int num, char *last)
{
	int i;

	i = 0;
	if (!str)
		return ;
}

int ft_open_anim(t_data *img, char *path, char *ext)
{
	int index;


	i = 0;
	while (i < MAX_IMG)
	{
		img[i] = ; 
		i++;
	}

}

int ft_animation_pars(t_global *f)
{
	f->anim = ft_calloc(MAX_IMG + 1, sizeof(void *));
	if (!f->anim)
	{
		perror("ft_calloc");
		return (-1);
	}

}

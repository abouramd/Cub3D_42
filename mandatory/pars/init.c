#include "pars.h"

void	set_null(t_pars *f, t_global *d)
{
	f->NO = NULL;
	f->SO = NULL;
	f->WE = NULL;
	f->EA = NULL;
	f->F = NULL;
	f->C = NULL;
	f->map = NULL;
	f->file_content = NULL;
	d->img.img = NULL;
	d->NO.img = NULL;
	d->SO.img = NULL;
	d->WE.img = NULL;
	d->EA.img = NULL;
}

void	free_data(t_global *d)
{
	if (d->map)
		ft_free(d->map);
	ft_destroy_image(d);
}

void	free_pars(t_pars *pars)
{
	if (pars->C)
		free(pars->C);
	if (pars->F)
		free(pars->F);
	if (pars->NO)
		free(pars->NO);
	if (pars->SO)
		free(pars->SO);
	if (pars->WE)
		free(pars->WE);
	if (pars->EA)
		free(pars->EA);
	if (pars->file_content)
		ft_free(pars->file_content);
	if (pars->map)
		ft_free(pars->map);
}

void	ft_destroy_image(t_global *f)
{
	if (f->mlx_win)
		mlx_destroy_window(f->mlx, f->mlx_win);
	if (f->NO.img)
		mlx_destroy_image(f->mlx, f->NO.img);
	if (f->SO.img)
		mlx_destroy_image(f->mlx, f->SO.img);
	if (f->WE.img)
		mlx_destroy_image(f->mlx, f->WE.img);
	if (f->EA.img)
		mlx_destroy_image(f->mlx, f->EA.img);
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
}

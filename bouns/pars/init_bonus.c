#include "../include/pars_bonus.h"

void	set_null(t_pars *f, t_global *d)
{
	f->no = NULL;
	f->so = NULL;
	f->we = NULL;
	f->ea = NULL;
	f->floor = NULL;
	f->ceil = NULL;
	f->map = NULL;
	f->file_content = NULL;
	d->img.img = NULL;
	d->no.img = NULL;
	d->so.img = NULL;
	d->we.img = NULL;
	d->ea.img = NULL;
}

void	free_data(t_global *d)
{
	if (d->map)
		ft_free(d->map);
	ft_destroy_image(d);
}

void	free_pars(t_pars *pars)
{
	if (pars->ceil)
		free(pars->ceil);
	if (pars->floor)
		free(pars->floor);
	if (pars->no)
		free(pars->no);
	if (pars->so)
		free(pars->so);
	if (pars->we)
		free(pars->we);
	if (pars->ea)
		free(pars->ea);
	if (pars->file_content)
		ft_free(pars->file_content);
	if (pars->map)
		ft_free(pars->map);
}

void	ft_destroy_image(t_global *f)
{
	if (f->mlx_win)
		mlx_destroy_window(f->mlx, f->mlx_win);
	if (f->no.img)
		mlx_destroy_image(f->mlx, f->no.img);
	if (f->so.img)
		mlx_destroy_image(f->mlx, f->so.img);
	if (f->we.img)
		mlx_destroy_image(f->mlx, f->we.img);
	if (f->ea.img)
		mlx_destroy_image(f->mlx, f->ea.img);
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
}

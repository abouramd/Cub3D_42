#include "pars.h"

int	create_rgb(int *p)
{
	return (0 << 24 | p[0] << 16 | p[1] << 8 | p[2]);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_creat_texters(t_global *f, t_pars *ptr)
{
    (void) f;
    (void) ptr;
	f->NO.addr = mlx_get_data_addr(f->NO.img, &f->NO.bits_per_pixel, &f->NO.line_length,
								&f->NO.endian);
	if (f->NO.img == NULL)
		return (put_err("NO", strerror(errno)), -1);

	f->SO.addr = mlx_get_data_addr(f->SO.img, &f->SO.bits_per_pixel, &f->SO.line_length,
								&f->SO.endian);
	if (f->SO.img == NULL)
		return (put_err("SO", strerror(errno)), -1);

	f->WE.addr = mlx_get_data_addr(f->WE.img, &f->WE.bits_per_pixel, &f->WE.line_length,
								&f->WE.endian);
	if (f->WE.img == NULL)
		return (put_err("WE", strerror(errno)), -1);
	
	f->EA.addr = mlx_get_data_addr(f->EA.img, &f->EA.bits_per_pixel, &f->EA.line_length,
								&f->EA.endian);
	if (f->EA.img == NULL)
		return (put_err("EA", strerror(errno)), -1);
    return 0;
}

int	ft_creat_image(t_global *f, t_pars *ptr)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (put_err("mlx_init", strerror(errno)), -1);
	f->NO.img = mlx_xpm_file_to_image(f->mlx, ptr->NO, &f->NO.width , &f->NO.heigth);
	if (f->NO.img == NULL)
		return (put_err("NO", strerror(errno)), -1);
	f->SO.img = mlx_xpm_file_to_image(f->mlx, ptr->SO, &f->SO.width , &f->SO.heigth);
	if (f->SO.img == NULL)
		return (put_err("SO", strerror(errno)), -1);
	f->WE.img = mlx_xpm_file_to_image(f->mlx, ptr->WE, &f->WE.width , &f->WE.heigth);
	if (f->WE.img == NULL)
		return (put_err("WE", strerror(errno)), -1);
	f->EA.img = mlx_xpm_file_to_image(f->mlx, ptr->EA, &f->EA.width , &f->EA.heigth);
	if (f->EA.img == NULL)
		return (put_err("EA", strerror(errno)), -1);
	return (0);
}

int	fill_data(t_global *f, t_pars *ptr)
{
	if (ft_creat_image(f, ptr) == -1)
		return (-1);
	if (ft_creat_texters(f, ptr) == -1)
		return (-1);
	f->map = ptr->map;
	ptr->map = NULL;
	f->player_x = ptr->player_x;
	f->player_y = ptr->player_y;
	f->F = create_rgb(ptr->F);
	f->draw.F = f->F;
	f->C = create_rgb(ptr->C);
	f->draw.C = f->C;
	f->field_of_view = ptr->field_of_view;
	return (0);
}

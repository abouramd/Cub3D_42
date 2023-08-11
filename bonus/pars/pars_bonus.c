#include "../include/pars_bonus.h"

#define HIEGTH_WRITE 100
#define WIDTH_WRITE 120

void	read_to_play(t_global *data, int x, int y)
{
	int		line;
	int		line_size;
	int		i;
	char	*s[11];

	line = 1;
	i = 0;
	line_size = 20;
	s[0] = "   Welcome to our cud3d :D";
	s[1] = " - Press <ENTER> key to start the game.";
	s[2] = " - Press \'W\' to go forward";
	s[3] = " - Press \'S\' to get back";
	s[4] = " - Press \'A\' to go left";
	s[5] = " - Press \'D\' to go right";
	s[6] = " - Press \'->\' to turn right";
	s[7] = " - Press \'<-\' to turn left";
	s[8] = " - Press \'ESC\' to quite";
	s[9] = " - ENJOY!";
	while (i++ < 9 && y < W_HEIGHT)
		mlx_string_put(data->mlx, data->mlx_win, x, y + line_size * line++,
			GREEN, s[i]);
}

void	start_game(t_global *f, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x == width / 2 - WIDTH_WRITE || y == height / 2 - HIEGTH_WRITE)
				my_mlx_pixel_put(&f->img, x, y, GREEN);
			if (x == width / 2 + WIDTH_WRITE || y == height / 2 + HIEGTH_WRITE)
				my_mlx_pixel_put(&f->img, x, y, GREEN);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->img.img, 0, 0);
	read_to_play(f, 0, 0);
}

int	git_info(t_global *f, int width, int height)
{
	f->mlx_win = mlx_new_window(f->mlx, width, height, "2d map");
	if (!f->mlx_win)
		return (-1);
	f->img.img = mlx_new_image(f->mlx, width, height);
	if (!f->img.img)
		return (-1);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
			&f->img.line_length, &f->img.endian);
	if (!f->img.addr)
		return (-1);
	f->start = false;
	start_game(f, width, height);
	return (0);
}

void	get_angle(t_global *f)
{
	f->map[(int)(f->player_y)][(int)(f->player_x)] = '0';
	f->player_x = f->player_x * CUB_SIZE + CUB_SIZE / 2;
	f->player_y = f->player_y * CUB_SIZE + CUB_SIZE / 2;
	if (f->field_of_view == 'E')
		f->angle_of_view = 0;
	else if (f->field_of_view == 'N')
		f->angle_of_view = M_PI_2;
	else if (f->field_of_view == 'W')
		f->angle_of_view = M_PI;
	else
		f->angle_of_view = 3 * M_PI_2;
}

int	pars(t_global *f, int ac, char **av)
{
	t_pars	ptr;

	if (ac != 2)
		return (put_err("Usage", "./cub3D file_name.cub"), -1);
	set_null(&ptr, f);
	if (check_file(&ptr, av[1]) == -1)
		return (free_pars(&ptr), -1);
	if (check_content(&ptr) == -1)
		return (free_pars(&ptr), -1);
	if (fill_data(f, &ptr) == -1)
		return (free_pars(&ptr), ft_destroy_image(f), -1);
	free_pars(&ptr);
	f->width = ft_strlen(f->map[0]);
	f->height = 0;
	while (f->map[f->height])
		f->height++;
	if (git_info(f, W_WIDTH, W_HEIGHT) == -1)
		return (ft_destroy_image(f), -1);
	get_angle(f);
	if (ft_animation_pars(f) == -1)
		return (ft_destroy_image(f), -1);
	f->timer = 0;
	f->event = false;
	return (0);
}

#include "pars.h"

int	map_check(t_pars *ptr, size_t x, size_t y, int *np)
{
	if (ptr->map[y][x] == '1')
		return (0);

	if (ptr->map[y][x] == ' ' || y == 0 || x == 0 || !ptr->map[y + 1] || !ptr->map[y][x + 1])
		return (put_err("the map should be sorounding by wall", ptr->map[y]), -1);
	if (!(ptr->map[y][x] == '0' || ptr->map[y][x] == 'N' || ptr->map[y][x] == 'S' || ptr->map[y][x] == 'E' || ptr->map[y][x] == 'W'))
				return (put_err("Unknowing char", ptr->map[y]), -1);
	if ((ptr->map[y][x] == 'N' || ptr->map[y][x] == 'S' || ptr->map[y][x] == 'E' || ptr->map[y][x] == 'W') && !(*np)++)
	{
		ptr->field_of_view = ptr->map[y][x];
		ptr->player_x = x;
		ptr->player_y = y;
	}
	else if ((ptr->map[y][x] == 'N' || ptr->map[y][x] == 'S' || ptr->map[y][x] == 'E' || ptr->map[y][x] == 'W') && *np)
		return (put_err("There is more then one player!!", ptr->map[y]), -1);
	ptr->map[y][x] = '1';
	if (map_check(ptr, x + 1, y, np) == -1)
		return (-1);
	if (map_check(ptr, x - 1, y, np) == -1)
		return (-1);
	if (map_check(ptr, x, y + 1, np) == -1)
		return (-1);
	if (map_check(ptr, x, y - 1, np) == -1)
		return (-1);

	return (0);
}

int	run_check(t_pars *ptr)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	int np = 0;
	while (ptr->map[x])
	{
		y = 0;
		while (ptr->map[x][y])
		{
			if ((ptr->map[x][y] == '0' || ptr->map[x][y] == 'E' || ptr->map[x][y] == 'N' || ptr->map[x][y] == 'S' || ptr->map[x][y] == 'W')
				&& map_check(ptr, y, x, &np) == -1)
				return (-1);
			else if (ptr->map[x][y] != '1' && ptr->map[x][y] != ' ')
				return (put_err("Unknowing char", ptr->map[x]), -1);
			y++;
		}
		x++;
	}
	if (!np)
		return (put_err("the file content", "There is no player!!"), -1);
	return (0);
}

int	copy_map(char ***dst, char **src)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (src[i])
		if (ft_strlen(src[i++]) + 1 > max)
			max = ft_strlen(src[i - 1]) + 1;
	(*dst) = malloc(sizeof(char *) * (i + 1));
	if (!(*dst))
		return (put_err("malloc", "alloction failed!!"), -1);
	i = 0;
	while (src[i])
	{
		(*dst)[i] = malloc(max);
		if (!(*dst)[i])
			return (put_err("malloc", "malloc failed!!"), -1);
		ft_memset((*dst)[i], ' ', max - 1);
		ft_memcpy((*dst)[i], src[i], ft_strlen(src[i]));
		(*dst)[i][max - 1] = 0;
		i++;
	}
	(*dst)[i] = NULL;
	return (0);
}


int	check_map(t_pars *ptr, char **s)
{

	if (copy_map(&ptr->map, s) == -1)
		return (-1);
	if (run_check(ptr) == -1)
		return (-1);
	ft_free(ptr->map);
	if (copy_map(&ptr->map, s) == -1)
		return (-1);
	return (0);
}

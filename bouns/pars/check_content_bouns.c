#include "../include/pars_bouns.h"

size_t	skip_white_space(char *str, size_t index)
{
	while (str && str[index])
	{
		if (str[index] != ' ')
			return (index);
		index++;
	}
	return (index);
}

char	*add_char(char *str, char c)
{
	char	s[2];
	char	*save;

	if (str)
	{
		s[0] = c;
		s[1] = 0;
		save = str;
		str = ft_strjoin(str, s);
		free(save);
		return (str);
	}
	else
	{
		save = malloc(2);
		save[0] = c;
		save[1] = 0;
		return (save);
	}
}

int	get_path(char **ptr, char *str, char *s)
{
	size_t	index;
	char	c;

	c = 0;
	index = 0;
	if ((*ptr))
		return (put_err("duplicate identifier", s), -1);
	index = skip_white_space(str, 0);
	while (str[index])
	{
		if (c == 0 && (str[index] == ' '))
			break ;
		if (!c && (str[index] == '\"' || str[index] == '\''))
			c = str[index];
		else if (c && str[index] == c)
			c = 0;
		else
			(*ptr) = add_char((*ptr), str[index]);
		index ++;
	}
	if (!(*ptr))
		return (put_err("there is no path", str - 3), -1);
	if (c)
		return (put_err("unclosed qout", str - 3), -1);
	if (str[skip_white_space(str, index)])
		return (put_err("you should put the path only", str - 3), -1);
	return (check_file_name((*ptr), ".xpm", "The file name should end with .xpm"));
}

int	get_nbr(int *ptr, char *str, size_t *index, char c)
{
	*index = skip_white_space(str, *index);
	if (ft_isdigit(str[*index]))
		(*ptr) = 0;
	else
		return (-1);
	while (ft_isdigit(str[*index]))
	{
		(*ptr) = (*ptr) * 10 + str[(*index)++] - '0';
		if ((*ptr) > 255)
			return (-1);
	}
	*index = skip_white_space(str, *index);
	if (str[*index] != c)
		return (-1);
	(*index)++;
	return 0;
}

int	get_color(int **ptr, char *str, char *s)
{
	size_t index = 0;

	if ((*ptr))
		return (put_err("duplicate identifier",s), -1);
	(*ptr) = ft_calloc(sizeof(int), 3);
	if (!(*ptr))
		return (put_err("ft_calloc", "allocation faild!!"), -1);
	if (get_nbr(&(*ptr)[0], str, &index, ',') == -1)
		return (put_err("informations problem", str - 2), -1);
	if (get_nbr(&(*ptr)[1], str, &index, ',') == -1)
		return (put_err("informations problem", str - 2), -1);
	if (get_nbr(&(*ptr)[2], str, &index, '\0') == -1)
		return (put_err("informations problem", str - 2), -1);
	return (0);
}

int	get_global(t_pars *ptr, char *str)
{
	size_t	index;

	index = skip_white_space(str, 0);
	if (!str[index])
		return (0);
	if (!strncmp(&str[index], "NO ", 3))
		return (get_path(&ptr->no, &str[index + 3], "NO"));
	if (!strncmp(&str[index], "SO ", 3))
		return (get_path(&ptr->so, &str[index + 3], "SO"));
	if (!strncmp(&str[index], "WE ", 3))
		return (get_path(&ptr->we, &str[index + 3], "WE"));
	if (!strncmp(&str[index], "EA ", 3))
		return (get_path(&ptr->ea, &str[index + 3], "EA"));
	if (!strncmp(&str[index], "F ", 2))
		return (get_color(&ptr->F, &str[index + 2], "F"));
	if (!strncmp(&str[index], "C ", 2))
		return (get_color(&ptr->C, &str[index + 2], "C"));
	if (ptr->no && ptr->so && ptr->we && ptr->ea && ptr->C && ptr->F)
		return (1);
	return (put_err("You miss some info!!", str), -1);
}


int check_xpm_files(t_pars *ptr)
{
	int fd;

	fd = open(ptr->no, O_RDONLY);
	if (fd == -1)
		return (put_err(ptr->no, strerror(errno)), -1);
	close(fd);
	fd = open(ptr->so, O_RDONLY);
	if (fd == -1)
		return (put_err(ptr->so, strerror(errno)), -1);
	close(fd);
	fd = open(ptr->we, O_RDONLY);
	if (fd == -1)
		return (put_err(ptr->we, strerror(errno)), -1);
	close(fd);
	fd = open(ptr->ea, O_RDONLY);
	if (fd == -1)
		return (put_err(ptr->ea, strerror(errno)), -1);
	close(fd);
	return 0;
}

int	check_content(t_pars *ptr)
{
	size_t	index;
	int		v;

	index = 0;
	v = 0;
	while (v == 0 && ptr->file_content && ptr->file_content[index])
	{
		v = get_global(ptr, ptr->file_content[index]);
		if (v == -1)
			return (-1);
		if (v == 1)
			break ;
		index++;
	}
	if (!ptr->no || !ptr->so || !ptr->we || !ptr->ea || !ptr->C || !ptr->F)
		return (put_err("the file content", "You miss some info!!"), -1);
	if (ptr->file_content[index] == NULL)
		return (put_err("the file content", "there is no map in the file!!"), -1);
	if (check_map(ptr, &ptr->file_content[index]) == -1)
		return (-1);
	if (check_xpm_files(ptr) == -1)
		return (-1);
	printf("no : |%s|\n", ptr->no);
	printf("SO : |%s|\n", ptr->so);
	printf("WE : |%s|\n", ptr->we);
	printf("EA : |%s|\n", ptr->ea);
	printf("F : %d | %d | %d\n", ptr->F[0], ptr->F[1], ptr->F[2]);
	printf("C : %d | %d | %d\n", ptr->C[0], ptr->C[1], ptr->C[2]);
	ft_putendl_fd("map", 1);
	print_2_arr(ptr->map);
	return (0);
}

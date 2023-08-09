#include "../include/pars_bonus.h"

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

int get_error(char **ptr, char *str, size_t	index, char c)
{
	if (!(*ptr))
		return (put_err("there is no path", str - 3), -1);
	if (c)
		return (put_err("unclosed qout", str - 3), -1);
	if (str[skip_white_space(str, index)])
		return (put_err("you should put the path only", str - 3), -1);
	return (check_file_name((*ptr), ".xpm",
			"The file name should end with .xpm"));
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
		index++;
	}
	return (get_error(ptr, str, index, c));
}

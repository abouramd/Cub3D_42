#include "../include/pars_bonus.h"

void	put_err(const char *str, const char *str2)
{
	write(2, "\033[1;3;31mError:", 15);
	if (str)
	{
		write(2, "\n\t", 2);
		write(2, str, ft_strlen(str));
	}
	if (str2)
	{
		write(2, " : ", 3);
		write(2, str2, ft_strlen(str2));
	}
	write(2, "\033[0m\n", 5);
}

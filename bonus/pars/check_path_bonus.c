/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:04:48 by abouramd          #+#    #+#             */
/*   Updated: 2023/08/11 10:04:49 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pars_bonus.h"

int	check_file_name(const char *str, char *ext, char *err)
{
	size_t	len;
	size_t	extlen;

	len = ft_strlen(str);
	extlen = ft_strlen(ext);
	if (len <= extlen || (ft_strrchr(str, '/') && ft_strlen(ft_strrchr(str, '/')
				+ 1) <= extlen))
		return (put_err(str, err), -1);
	while (extlen > 0)
	{
		if (str[len - 1] != ext[extlen - 1])
			return (put_err(str, err), -1);
		extlen--;
		len--;
	}
	return (0);
}

static int	check_file_existed(t_pars *ptr, const char *str)
{
	int		fd;
	char	*p;
	char	**save;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (put_err(str, strerror(errno)), -1);
	p = get_next_line(fd);
	if (p == NULL)
		return (close(fd), put_err(str, "Empty file"), -1);
	while (p)
	{
		if (p[ft_strlen(p) - 1] == '\n')
			p[ft_strlen(p) - 1] = '\0';
		save = ptr->file_content;
		ptr->file_content = ft_ultimate_join(ptr->file_content, p);
		ft_free(save);
		free(p);
		p = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_file(t_pars *ptr, const char *str)
{
	if (check_file_name(str, ".cub", \
	"The file name should end with .cub") == -1)
		return (-1);
	if (check_file_existed(ptr, str) == -1)
		return (-1);
	return (0);
}

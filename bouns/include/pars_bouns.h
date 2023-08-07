#ifndef PARS_BONUS_H
# define PARS_BONUS_H

# include "cub_bouns.h"

typedef struct s_pars
{
	char	*no;
	char	*SO;
	char	*WE;
	char	*EA;
	int	*F;
	int	*C;
	char	**map;
	char	**file_content;
	size_t	player_x;
	size_t	player_y;
	char	field_of_view;
}			t_pars;

/* print error in stderr */
void	put_err(const char *str, const char *str2);

/* check file name */
int			check_file_name(const char *str, char *ext, char *err);

/* init the data */
void		set_null(t_pars *f, t_global *d);

/* check path */
int			check_file(t_pars *ptr, const char *str);

/* start read the file */
int			check_content(t_pars *ptr);

/* t_pars free */
void		free_pars(t_pars *pars);

/* check the map */
int check_map(t_pars *ptr, char **s);

/* fill data */
int fill_data(t_global *f, t_pars *ptr);

/* destroy image */
void ft_destroy_image(t_global *f);

/* animation setup */
int ft_animation_pars(t_global *f);

#endif // PARS_H

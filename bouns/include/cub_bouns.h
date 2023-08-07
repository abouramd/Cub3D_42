#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include <fcntl.h>
# include <mlx.h>
#include "../../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include "../../libft/libft.h"
# include <math.h>

# if defined(__APPLE__)
# define	KEY_W 13
# define	KEY_LEFT 123
# define	KEY_S 1
# define	KEY_RIGHT 124
# define	KEY_ECH 53
# define	KEY_Q 12
# define	KEY_SP 49
# define	KEY_ENTER 36
# define	KEY_A 0
# define	KEY_D 2
# else
# define	KEY_W 119
# define	KEY_LEFT 65361
# define	KEY_S 115
# define	KEY_RIGHT 65363
# define	KEY_ECH 65307
# define	KEY_Q 113
# define	KEY_SP 32
# define	KEY_ENTER 65293
# endif

# define TWOD 0

# undef W_HEIGTH
# define W_HEIGTH 1000
# undef W_WIDTH
# define W_WIDTH 2000


#undef BLACK
#define BLACK 0x000000
#undef RED
#define RED 0xAA0000
#undef GREEN
#define GREEN 0x00AA00
#undef BLUE
#define BLUE 0x0000AA
#undef WHITE
#define WHITE 0xAAAAAA
#undef CYAN
#define CYAN 0x00AAAA
#undef MAGENTA
#define MAGENTA 0xAA00AA
#undef YELLOW
#define YELLOW 0xAAAA00
#undef GREY
#define GREY 0x808080

#undef CUB_SIZE
#define CUB_SIZE 40

#undef P_STEP
#define P_STEP 10

#undef ROTAT_ANG
#define ROTAT_ANG 0.05

#define WALL_PROJ(d) (CUB_SIZE * W_HEIGTH / d);

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	heigth;
	int	width;
}		t_data;

typedef struct s_anim
{
	void	**animation;
} t_anim;

typedef struct s_global
{
	void	*mlx;
	void	*mlx_win;
	t_data 	img;
	t_data 	mini;
	t_data	no;
	t_data	SO;
	t_data	WE;
	t_data	EA;
	int	F;
	int	C;
	char	**map;
	double	player_x;
	double	player_y;
	char	field_of_view;
	double	angle_of_view;
	bool	start;
	int	width;
	int	hiegth;
	bool	event;
	t_anim	anim;
}		t_global;


void	print_2_arr(char **ptr);

int		pars(t_global *f, int ac, char **av);

void	free_data(t_global *d);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	put_err(const char *str, const char *str2);

void	ray_casting(t_global *d);


#endif // CUB_H


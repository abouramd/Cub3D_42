#ifndef RAY_CASTING_H
#define RAY_CASTING_H
#include "cub.h"

int ft_loop(t_global *data);
void map_2d(t_global *data);
int ft_destroy_win(t_global *data);
int ft_key(int key, t_global* data);
void ft_move(t_global *data, double ang);

#endif // !RAY_CASTING_H

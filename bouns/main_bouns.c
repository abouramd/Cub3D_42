#include "include/cub_bouns.h"

int main(int ac, char **av)
{
    
    t_global d;
    if (pars(&d, ac, av) == -1)
        return 1;
    ray_casting(&d);
    free_data(&d);
    //system("leaks cub3D");
    return 0;
}

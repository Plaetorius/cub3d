#include "cub3d.h"



int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	if (parsing(av[1], &vars) == false)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

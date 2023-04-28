#include "cub3d.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (write(2, "Error\n", 6), EXIT_FAILURE);
	(void)ac;
	(void)av;
	return (EXIT_SUCCESS);
}

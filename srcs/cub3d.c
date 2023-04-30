#include "cub3d.h"

static void	set_to_zero(t_vars *vars, t_map *map)
{
	map->path_north = NULL;
	map->path_south = NULL;
	map->path_east = NULL;
	map->path_west = NULL;
	map->ceiling_color[0] = 0;
	map->ceiling_color[1] = 0;
	map->ceiling_color[2] = 0;
	map->floor_color[0] = 0;
	map->floor_color[1] = 0;
	map->floor_color[2] = 0;
	map->param_number = 0;
	map->heigth = 0;
	map->length = 0;
	vars->file_content = NULL;
	vars->map = map;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_map	map;

	if (ac != 2)
		return (error_str("Usage: ./cub3d path/to/map.cub"), EXIT_FAILURE);
	set_to_zero(&vars, &map);
	if (parsing(av[1], &vars, &map) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

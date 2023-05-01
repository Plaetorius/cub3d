#include "cub3d.h"

bool	line_correct(const char **map_content, int i, t_map *map)
{
	const char		*line = map_content[i];
	const size_t	len = ft_strlen(line);
	int				j;

	(void)len;
	j = 0;
	if (i == 0 || i == map->heigth - 1)
		if (ft_strchr(line, '0') || ft_cset_in_str(PLAYER, (char *)line))
			return (error_str("Map not closed"), false);
	while (line[j])
	{
		j = 0;
		while (!ft_c_in_str(line[j], FREE))
			++j;
		if (j == 0)
		{
			
		}
		else if (j == map->length)
		{

		}
		else
		{

		}
		++j;
	}
	return (true);
}

// bool	find_coords_walls(int coords[2], t_vars *vars, t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 2)
// 		return (false);
// 	return (true);
// }

bool	map_correct(t_map *map)
{
	const char	**map_content = (const char **)map->map;
	int			i;

	ft_printf("Map first line\n%s", map->map[0]);
	ft_printf("Map last line\n%s", map->map[map->heigth - 1]);
	i = 0;
	while (map->map[i])
	{
		if (line_correct(map->map, i, map) == false)
			return (false);

	}



	return (true);
}

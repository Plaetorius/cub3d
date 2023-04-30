#include "cub3d.h"

bool	line_correct(const char *line, int i, t_map *map)
{
	int	j;

	j = 1;
	if (i == map->first_line || i == map->first_line + map->heigth - 1)
		if (ft_strchr(line, '0') != NULL)
			return (error_str("Map not closed"), false);
	// while (line[j])
	// {
	// 	if (j == 0)
	// 		return (false);
	// 	++j;
	// }
	return (true);
}

bool	map_correct(t_vars *vars, t_map *map)
{
	const char	**content = (const char **)vars->file_content;
	int			i;

	i = map->first_line;
	ft_printf("Map first line %s", content[map->first_line]);
	ft_printf("Map last line %s", content[map->first_line + map->heigth - 1]);
	while (content[i])
	{
	// ft_printf("--------------------Segfault-----------------\n");
		if (line_correct(content[i], i, map) == false)
			return (error_str("Bad map format"), false);
		++i;
	}
	return (true);
}

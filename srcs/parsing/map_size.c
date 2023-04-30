#include "cub3d.h"

static bool	is_line_empty(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_c_in_str(line[i], SPACES))
			return (false);
		++i;
	}
	return (true);
}

/*
	-1 to get rid of the \n for map->length
*/
static bool	bad_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_c_in_str(line[i], PLAYER) && !ft_c_in_str(line[i], SPACES)
			&& !ft_c_in_str(line[i], "01"))
			return (true);
		++i;
	}
	if (i > map->length)
		map->length = i;
	if (i > 1)
		map->heigth++;
	return (false);
}

static bool	is_line_a_texture(int line_nb, t_map *map)
{
	if (line_nb == map->param_lines[0])
		return (true);
	else if (line_nb == map->param_lines[1])
		return (true);
	else if (line_nb == map->param_lines[2])
		return (true);
	else if (line_nb == map->param_lines[3])
		return (true);
	else if (line_nb == map->param_lines[4])
		return (true);
	else if (line_nb == map->param_lines[5])
		return (true);
	return (false);
}

bool	map_size(t_vars *vars, t_map *map)
{
	int			i;
	const char	**content = (const char **)vars->file_content;
	bool		found_first;

	i = 0;
	found_first = false;
	while (content[i])
	{
		if (!is_line_a_texture(i, map))
		{
			if (bad_line((char *)content[i], map))
				return (error_str("Bad char in map"), false);
			else if (found_first == false && !is_line_empty(content[i]))
			{
				found_first = true;
				map->first_line = i;
			}
		}
		++i;
	}

	if (map->heigth < 3 && map->length < 3)
		return (error_str("Map too small"), false);
	return (true);
}

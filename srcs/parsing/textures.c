#include "cub3d.h"

/*
	Assign To map
	Could be protected by checking if the value that is about tot be modified
	isn't NULL. Permits verification that each parameter is only entered once,
	and that all parameters have been given

*/
static bool	assign_to_map(char *id, char *value, t_map *map)
{
	const char	**colors = (const char **)ft_split(value, ',');

	if (!colors)
		return (false);
	if (!ft_strncmp(id, "NO", 2))
		map->path_north = value;
	else if (!ft_strncmp(id, "SO", 2))
		map->path_south = value;
	else if (!ft_strncmp(id, "EA", 2))
		map->path_east = value;
	else if (!ft_strncmp(id, "WE", 2))
		map->path_west = value;
	else if (!ft_strncmp(id, "F", 1))
	{
		map->floor_color[0] = ft_atoi(colors[0]);
		map->floor_color[1] = ft_atoi(colors[1]);
		map->floor_color[2] = ft_atoi(colors[2]);
	}
	else if (!ft_strncmp(id, "C", 1))
	{
		map->ceiling_color[0] = ft_atoi(colors[0]);
		map->ceiling_color[1] = ft_atoi(colors[1]);
		map->ceiling_color[2] = ft_atoi(colors[2]);
	}
	return (ft_free_strs((char **)colors), true);
}

static char	*find_id(char *id, char *line, int line_nb, t_map *map)
{
	const size_t	len_id = ft_strlen(id);
	char			*tmp;
	char			*info;
	int				i;

	i = 0;
	while (line[i] && ft_c_in_str(line[i], SPACES))
		++i;
	if (ft_strncmp(id, line + i, len_id) != 0)
		return (NULL);
	tmp = ft_strtrim(line + i + len_id, SPACES);
	i = 0;
	while (tmp[i] && !ft_c_in_str(tmp[i], SPACES))
		++i;
	if (i == 0)
		return (NULL);
	info = malloc(sizeof(char) * i + 1);
	if (!info)
		return (NULL);
	info[i] = '\0';
	while (--i >= 0)
		info[i] = tmp[i];
	free(tmp);
	map->param_lines[map->param_number++] = line_nb;
	return (info);
}

bool	get_textures_info(t_vars *vars, t_map *map)
{
	const char	**content = (const char **)vars->file_content;
	const char	ids[6][4] = {"NO ", "SO ", "EA ", "WE ", "F ", "C "};
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (content[i])
	{
		j = 0;
		while (j < 6)
		{
			tmp = find_id((char *)ids[j], (char *)content[i], i, map);
			if (tmp && !assign_to_map((char *)ids[j], tmp, map))
				return (perror("malloc"), false);
			++j;
		}
		++i;
	}
	if (map->param_number != 6)
		return (error_str("Not enough parameters for textures"), false);
	return (true);
}

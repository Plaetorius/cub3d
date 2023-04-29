#include "cub3d.h"

/*
	content opener
	This function takes a
*/
bool	file_opener(char *file_name, t_vars *vars)
{
	int		fd;
	int		i;
	int		lines;
	char	buff[1];
	char	**content;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("open\n"), false);
	lines = 0;
	while (read(fd, buff, 1))
		lines += buff[0] == '\n';
	close(fd);
	content = malloc(sizeof (char *) * (lines + 1));
	if (!content)
		return (perror("malloc\n"), false);
	content[lines] = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_free_strs(content), perror("open\n"), false);
	i = 0;
	while (i < lines)
		content[i++] = get_next_line(fd);
	vars->file_content = content;
	return (close(fd), true);
}

bool	parsing(char *file_name, t_vars *vars)
{
	bool	failed;

	failed = false;
	failed |= ft_strncmp(".cub", file_name + ft_strlen(file_name) - 4, 4) == 0;
	failed |= file_opener(file_name, vars) == true;
	int i = 0;
	const char **map = (const char **) vars->file_content;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("Parsing: %d (1+ is success, 0 is failure)\n", failed);
	return (failed);
}

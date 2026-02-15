/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:32:05 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 01:29:13 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

static void	assign_map_line(char **map, int i, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		line[len - 1] = '\0';
	map[i] = line;
}

static void	free_lines(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	fill_map(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		fd;

	data->map.map = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.map)
		return ;
	data->map.map[data->map.height] = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		return (perror(file));
	}
	i = 0;
	line = get_next_line(fd);
	while (i < data->map.height && line)
	{
		if (is_map_line(line))
			assign_map_line(data->map.map, i++, line);
		else
			free(line);
		line = get_next_line(fd);
	}
	free_lines(line, fd);
	close(fd);
}

char	**read_map(t_data *data, char *file)
{
	if (get_map_dimensions(data, file, &data->map.max_width) != 0)
		return (NULL);
	fill_map(data, file);
	return (data->map.map);
}

void	parsing_map(t_data *data, char *file)
{
	data->map.map = read_map(data, file);
	if (valid_characters(data->map.map))
	{
		free_map(data->map.map);
		free_wall_paths(&data->textures);
		exit(1);
	}
	if (!validate_map_boundaries(&data->map))
	{
		write(2, "Error\nMap is not surrounded by walls\n", 38);
		free_map(data->map.map);
		free_wall_paths(&data->textures);
		exit(1);
	}
	validate_player(data);
	path_validation(data);
	map_padding(&data->map);
}

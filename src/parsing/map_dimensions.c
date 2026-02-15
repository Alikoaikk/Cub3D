/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:09:42 by akoaik            #+#    #+#             */
/*   Updated: 2026/01/28 16:18:38 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

static void	empty_line_error(char *line, int fd, t_data *data)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free_wall_paths(&data->textures);
	printf("Error\nEmpty line inside map\n");
	exit(1);
}

static void	process_map_line(t_data *data, char *line, int *max_width,
		int *new_line)
{
	if (is_map_line(line))
	{
		if (new_line[0] && new_line[1])
			empty_line_error(line, data->fd, data);
		new_line[0] = 1;
		process_line(line, max_width, &data->map);
	}
	else if (new_line[0] && is_empty_line(line))
		new_line[1] = 1;
}

int	get_map_dimensions(t_data *data, char *file, int *max_width)
{
	char	*line;
	int		fd;
	int		new_line[2];

	*max_width = 0;
	data->map.height = 0;
	new_line[0] = 0;
	new_line[1] = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror(file), -1);
	data->fd = fd;
	line = get_next_line(fd);
	while (line)
	{
		process_map_line(data, line, max_width, new_line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 00:05:34 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 15:56:44 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	dfs(int *leak, t_data *data, int x, int y)
{
	int	len;

	if (x < 0 || y < 0 || y >= data->map.height)
	{
		*leak = 1;
		return ;
	}
	len = ft_strlen(data->map.map[y]);
	if (x >= len)
	{
		*leak = 1;
		return ;
	}
	if (data->map.copy[y][x] == ' ')
	{
		*leak = 1;
		return ;
	}
	if (data->map.copy[y][x] == '1' || data->map.copy[y][x] == 'c')
		return ;
	data->map.copy[y][x] = 'c';
	dfs(leak, data, x + 1, y);
	dfs(leak, data, x - 1, y);
	dfs(leak, data, x, y + 1);
	dfs(leak, data, x, y - 1);
}

int	flood_fill(t_data *data)
{
	int	x;
	int	y;
	int	leak;

	x = data->player.x;
	y = data->player.y;
	leak = 0;
	dfs(&leak, data, x, y);
	if (leak == 1)
		return (0);
	return (1);
}

void	path_validation(t_data *data)
{
	char	**copy;

	copy = duplicate_map(&data->map);
	if (!copy)
	{
		write(2, "Error\nFailed in memory allocation\n", 35);
		exit(1);
	}
	data->map.copy = copy;
	if (!flood_fill(data))
	{
		free_split(copy);
		free_split(data->map.map);
		free_wall_paths(&data->textures);
		write(2, "Error\nInvalid Path\n", 20);
		exit(1);
	}
	free_split(copy);
}

char	**duplicate_map(t_map *map)
{
	int		i;
	char	**copy;

	copy = malloc((map->height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			free_split(copy);
			return (NULL);
		}
		i++;
	}
	copy[map->height] = NULL;
	return (copy);
}

void	process_line(char *line, int *max_width, t_map *map)
{
	int	len;

	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		len--;
	if (*max_width < len)
		*max_width = len;
	map->height++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 00:03:41 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 16:27:27 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0 || ft_strncmp(line + i, "SO", 2) == 0
		|| ft_strncmp(line + i, "EA", 2) == 0
		|| ft_strncmp(line + i, "WE", 2) == 0)
		return (0);
	if (line[i] == 'F' || line[i] == 'C')
		return (0);
	if (is_empty_line(line))
		return (0);
	return (1);
}

int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (1);
	return (0);
}

int	valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_character(map[i][j]))
			{
				write(2, "Error\nInvalid character is found\n", 34);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	collect_player_position(t_data *data)
{
	int	player_found;
	int	i;
	int	j;

	player_found = 0;
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				player_found++;
				data->player.x = (double)j + 0.5 ;
				data->player.y = (double)i + 0.5 ;
				data->player.orientation = data->map.map[i][j];
				data->map.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (player_found);
}

void	validate_player(t_data *data)
{
	int	player_found;

	player_found = collect_player_position(data);
	if (player_found > 1)
	{
		write(2, "Error\nThere is more than one player\n", 37);
		free_map(data->map.map);
		free_wall_paths(&data->textures);
		exit(1);
	}
	if (player_found == 0)
	{
		write(2, "Error\nNo player found in the map\n", 34);
		free_map(data->map.map);
		free_wall_paths(&data->textures);
		exit(1);
	}
}

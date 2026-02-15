/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:58:35 by msafa             #+#    #+#             */
/*   Updated: 2026/01/09 01:22:24 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

char	*create_padded_line(char *line, int max_width)
{
	int		j;
	char	*new_line;

	j = 0;
	new_line = malloc(sizeof(char) * (max_width + 1));
	if (!new_line)
	{
		write(2, "Error\nAllocation failed in create_padded_line\n", 46);
		exit(1);
	}
	while (line[j])
	{
		new_line[j] = line[j];
		j++;
	}
	while (j < max_width)
	{
		new_line[j] = ' ';
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

void	map_padding(t_map *map)
{
	int	i;

	map->padded_map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->padded_map)
	{
		write(2, "Error\nAllocation failed in map_padding\n", 40);
		exit(1);
	}
	i = 0;
	while (map->map[i])
	{
		map->padded_map[i] = create_padded_line(map->map[i], map->max_width);
		i++;
	}
	map->padded_map[i] = NULL;
}

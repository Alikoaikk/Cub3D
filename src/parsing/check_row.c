/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:53:33 by akoaik            #+#    #+#             */
/*   Updated: 2026/01/28 15:56:49 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	check_row_walls_only(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1' && row[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_row_edges(char *row)
{
	int	i;
	int	len;

	i = 0;
	while (row[i] == ' ')
		i++;
	if (row[i] && row[i] != '1')
		return (0);
	len = ft_strlen(row);
	if (len == 0)
		return (0);
	len--;
	while (len >= 0 && row[len] == ' ')
		len--;
	if (len >= 0 && row[len] != '1')
		return (0);
	return (1);
}

int	validate_map_boundaries(t_map *map)
{
	int	i;

	if (!map->map || !map->map[0])
		return (0);
	if (!check_row_walls_only(map->map[0]))
		return (0);
	if (map->height > 1 && !check_row_walls_only(map->map[map->height - 1]))
		return (0);
	i = 1;
	while (i < map->height - 1)
	{
		if (!check_row_edges(map->map[i]))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:46:09 by msafa             #+#    #+#             */
/*   Updated: 2026/01/26 00:09:26 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	check_line(char *line)
{
	if (!line)
		return (0);
	if (is_empty_line(line))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	validate_characters(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] && !(s[i] >= '0' && s[i] <= '9'))
		{
			write(2, "Error\nExtra characters are not allowed\n", 40);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_count(int count)
{
	if (count != 3)
	{
		write(2, "Error\nRGB must have exactly 3 values\n", 37);
		return (1);
	}
	return (0);
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	init_walls(t_walls *walls, char *line, char *path)
{
	if (ft_strncmp(line, "EA", 2) == 0)
		walls->east_path = path;
	else if (ft_strncmp(line, "NO", 2) == 0)
		walls->north_path = path;
	else if (ft_strncmp(line, "SO", 2) == 0)
		walls->south_path = path;
	else if (ft_strncmp(line, "WE", 2) == 0)
		walls->west_path = path;
}

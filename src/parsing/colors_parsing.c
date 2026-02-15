/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:38:24 by msafa             #+#    #+#             */
/*   Updated: 2026/01/27 23:23:30 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

static int	handle_floor_color(char *trimmed, t_colors *colors, int *count,
		t_checker *checker)
{
	if (checker->f)
		return (free(trimmed), write(2, "Error\nDuplicate floor color\n", 29),
			1);
	checker->f = 1;
	if (extract_and_fill(trimmed + 1, colors->floor_color))
		return (free(trimmed), 1);
	(*count)++;
	return (0);
}

static int	handle_ceiling_color(char *trimmed, t_colors *colors, int *count,
		t_checker *checker)
{
	if (checker->c)
		return (free(trimmed), write(2, "Error\nDuplicate ceiling color\n", 31),
			1);
	checker->c = 1;
	if (extract_and_fill(trimmed + 1, colors->ceiling_color))
		return (free(trimmed), 1);
	(*count)++;
	return (0);
}

int	validate_colors(char *line, t_colors *colors, int *count,
		t_checker *checker)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t");
	if (trimmed[0] != 'F' && trimmed[0] != 'C')
	{
		free(trimmed);
		write(2, "Error\nInvalid identifier\n", 26);
		return (1);
	}
	if (trimmed[0] == 'F')
	{
		if (handle_floor_color(trimmed, colors, count, checker))
			return (1);
	}
	else if (trimmed[0] == 'C')
	{
		if (handle_ceiling_color(trimmed, colors, count, checker))
			return (1);
	}
	free(trimmed);
	return (0);
}

void	parse_colors(char **stash, t_data *data, t_checker *checker)
{
	char	*buffer;
	char	*line;
	int		count;

	count = 0;
	if (!*stash)
		buffer = fill_buffer(data);
	while (count < 2)
	{
		buffer = fill_buffer(data);
		line = extract_line(stash, buffer);
		if (!check_line(line))
			continue ;
		if (line && validate_colors(line, &data->colors, &count, checker))
			colors_cleanup(line, stash, data);
		if (line)
			free(line);
	}
	if (*stash)
		free(*stash);
}

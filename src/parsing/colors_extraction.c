/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_extraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:16:41 by akoaik            #+#    #+#             */
/*   Updated: 2026/01/28 01:28:32 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

static int	process_color_value(char **aux, int colors[3], int count)
{
	char	*tmp;

	tmp = aux[count];
	aux[count] = ft_strtrim(aux[count], " \t");
	free(tmp);
	if (validate_characters(aux[count]))
		return (1);
	if (count < 3)
	{
		colors[count] = ft_atoi(aux[count]);
		if (colors[count] < 0 || colors[count] > 255)
		{
			write(2, "Error\nRGB values must be in range [0,255]\n", 43);
			return (1);
		}
	}
	return (0);
}

int	extract_and_fill(char *line, int colors[3])
{
	int		i;
	int		count;
	char	**aux;

	i = 0;
	count = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i])
		return (write(2, "Error\nMissing floor colors\n", 28), 1);
	aux = ft_split(line, ',');
	while (aux[count])
	{
		if (process_color_value(aux, colors, count))
			return (free_split(aux), 1);
		count++;
	}
	if (check_count(count))
		return (free_split(aux), 1);
	return (free_split(aux), 0);
}

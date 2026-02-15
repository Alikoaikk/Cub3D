/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:07:26 by msafa             #+#    #+#             */
/*   Updated: 2026/01/05 22:16:22 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	init_checker(t_checker *checker)
{
	checker->ea = 0;
	checker->no = 0;
	checker->so = 0;
	checker->we = 0;
	checker->f = 0;
	checker->c = 0;
	return ;
}

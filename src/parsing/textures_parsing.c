/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:32:03 by msafa             #+#    #+#             */
/*   Updated: 2026/01/27 23:23:41 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	path_exist(t_walls *walls, char *line, char *temp)
{
	char	*path;
	int		fd;
	int		end;

	end = 0;
	while (temp[end] && temp[end] != ' ' && temp[end] != '\t'
		&& temp[end] != '\n')
		end++;
	path = ft_substr(temp, 0, end);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Texture path does not exist\n", 29);
		free(path);
		return (1);
	}
	close(fd);
	init_walls(walls, line, path);
	return (0);
}

int	validate_texture_path(t_walls *walls, char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i])
	{
		write(2, "Error\nTexture path is missing\n", 31);
		return (1);
	}
	if (path_exist(walls, line, line + i))
	{
		write(2, "Error\nTexture file not found\n", 30);
		return (1);
	}
	return (0);
}

int	check_appearance(t_checker *checker, char *line)
{
	if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (checker->ea)
			return (1);
		checker->ea = 1;
	}
	else if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (checker->no)
			return (1);
		checker->no = 1;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (checker->so)
			return (1);
		checker->so = 1;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (checker->we)
			return (1);
		checker->we = 1;
	}
	return (0);
}

char	*allocate_line(int size, char **stash)
{
	char	*line;
	int		j;

	j = 0;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
	{
		perror("Error\n");
		exit(1);
	}
	while (j < size)
	{
		line[j] = (*stash)[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

void	parse_textures(t_data *data, t_checker *checker, t_walls *walls,
		char **stash)
{
	int		count;
	char	*buffer;
	char	*line;

	count = 0;
	while (count < 4)
	{
		buffer = fill_buffer(data);
		line = extract_line(stash, buffer);
		if (!line)
			continue ;
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (line && validate_line(line, checker, walls))
		{
			free(line);
			exit(1);
		}
		if (line)
			free(line);
		count++;
	}
}

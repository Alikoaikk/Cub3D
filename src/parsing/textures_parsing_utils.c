/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:24:48 by akoaik            #+#    #+#             */
/*   Updated: 2026/01/27 23:24:52 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

char	*fill_buffer(t_data *data)
{
	ssize_t	bytes_read;
	char	temp[128];
	char	*buffer;

	bytes_read = read(data->fd, temp, 127);
	if (bytes_read < 0)
	{
		perror("Error\n");
		exit(1);
	}
	if (bytes_read == 0)
		return (NULL);
	temp[bytes_read] = '\0';
	buffer = malloc(bytes_read + 1);
	if (!buffer)
		exit(1);
	ft_strlcpy(buffer, temp, bytes_read + 1);
	return (buffer);
}

void	update_stash(char **stash, char *buffer)
{
	char	*new_stash;

	if (!buffer)
		return ;
	if (!*stash)
		*stash = ft_strdup(buffer);
	else
	{
		new_stash = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = new_stash;
	}
	free(buffer);
}

char	*extract_line_from_stash(char **stash)
{
	char	*line;
	char	*new_stash;
	int		i;

	i = 0;
	if (!*stash)
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
	{
		line = allocate_line(i, stash);
		new_stash = ft_strdup(*stash + i + 1);
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*extract_line(char **stash, char *buffer)
{
	char	*line;

	update_stash(stash, buffer);
	line = extract_line_from_stash(stash);
	return (line);
}

int	validate_line(char *line, t_checker *checker, t_walls *walls)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t");
	if (ft_strncmp(trimmed, "NO", 2) != 0 && ft_strncmp(trimmed, "WE", 2) != 0
		&& ft_strncmp(trimmed, "SO", 2) != 0 && ft_strncmp(trimmed, "EA",
			2) != 0)
	{
		write(2, "Error\nInvalid identifier\n", 25);
		free(trimmed);
		return (1);
	}
	if (check_appearance(checker, trimmed))
	{
		write(2, "Error\nRepetitive identifier\n", 29);
		free(trimmed);
		return (1);
	}
	if (validate_texture_path(walls, trimmed))
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

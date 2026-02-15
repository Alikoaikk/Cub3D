/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:32:25 by msafa             #+#    #+#             */
/*   Updated: 2026/01/05 22:16:16 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	file_validation(char *file, t_data *data)
{
	int	fd;
	int	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		close(fd);
		exit(1);
	}
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp((file + len - 4), ".cub", 4) != 0)
	{
		write(2, "Error\nInvalid file extension", 29);
		exit(1);
	}
	data->fd = fd;
	return ;
}

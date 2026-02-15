/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:28:20 by akoaik            #+#    #+#             */
/*   Updated: 2026/01/28 00:50:03 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_textures *textures, void *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (textures->walls[i].img)
			mlx_destroy_image(mlx, textures->walls[i].img);
		i++;
	}
}

void	free_wall_paths(t_walls *walls)
{
	if (walls->north_path)
		free(walls->north_path);
	if (walls->south_path)
		free(walls->south_path);
	if (walls->west_path)
		free(walls->west_path);
	if (walls->east_path)
		free(walls->east_path);
}

void	colors_cleanup(char *line, char **stash, t_data *data)
{
	free(line);
	if (*stash)
		free(*stash);
	free_wall_paths(&data->textures);
	exit(1);
}

int	exit_game(t_data *data)
{
	free_map(data->map.map);
	free_map(data->map.padded_map);
	free_wall_paths(&data->textures);
	free_textures(&data->walls, data->mlx.mlx);
	if (data->wand.img)
		mlx_destroy_image(data->mlx.mlx, data->wand.img);
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	if (data->mlx.game)
		mlx_destroy_window(data->mlx.mlx, data->mlx.game);
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	exit(0);
}

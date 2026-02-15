/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:31:21 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 00:45:57 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	load_north_texture(t_texture *walls, void *mlx, char *path)
{
	walls->img = mlx_xpm_file_to_image(mlx, path, &walls->width,
			&walls->height);
	if (!walls->img)
		return (-1);
	walls->addr = (int *)mlx_get_data_addr(walls->img, &walls->bpp,
			&walls->line_len, &walls->endian);
	return (0);
}

int	load_south_texture(t_texture *walls, void *mlx, char *path)
{
	walls->img = mlx_xpm_file_to_image(mlx, path, &walls->width,
			&walls->height);
	if (!walls->img)
		return (-1);
	walls->addr = (int *)mlx_get_data_addr(walls->img, &walls->bpp,
			&walls->line_len, &walls->endian);
	return (0);
}

int	load_west_texture(t_texture *walls, void *mlx, char *path)
{
	walls->img = mlx_xpm_file_to_image(mlx, path, &walls->width,
			&walls->height);
	if (!walls->img)
		return (-1);
	walls->addr = (int *)mlx_get_data_addr(walls->img, &walls->bpp,
			&walls->line_len, &walls->endian);
	return (0);
}

int	load_east_texture(t_texture *walls, void *mlx, char *path)
{
	walls->img = mlx_xpm_file_to_image(mlx, path, &walls->width,
			&walls->height);
	if (!walls->img)
		return (-1);
	walls->addr = (int *)mlx_get_data_addr(walls->img, &walls->bpp,
			&walls->line_len, &walls->endian);
	return (0);
}

int	load_textures(t_textures *textures, t_mlx *mlx, t_walls *walls)
{
	if ((load_north_texture(&textures->walls[NORTH], mlx->mlx,
				walls->north_path) < 0))
		return (-1);
	if ((load_south_texture(&textures->walls[SOUTH], mlx->mlx,
				walls->south_path) < 0))
		return (-1);
	if ((load_west_texture(&textures->walls[WEST], mlx->mlx,
				walls->west_path) < 0))
		return (-1);
	if ((load_east_texture(&textures->walls[EAST], mlx->mlx,
				walls->east_path) < 0))
		return (-1);
	return (0);
}

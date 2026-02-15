/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:37:06 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 18:19:03 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	load_wand(t_texture *wand, void *mlx)
{
	wand->img = mlx_xpm_file_to_image(mlx, "textures/wand.xpm", &wand->width,
			&wand->height);
	if (!wand->img)
		return (-1);
	wand->addr = (int *)mlx_get_data_addr(wand->img, &wand->bpp,
			&wand->line_len, &wand->endian);
	return (0);
}

void	put_pixel_to_screen(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	mlx->addr[y * (mlx->line_len / 4) + x] = color;
}

void	draw_wall_slice(t_data *data, int x, t_texture *tex)
{
	t_ray	*ray;
	int		y;

	ray = &data->ray;
	ray->step = (double)tex->height / (double)ray->line_height;
	ray->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2)
		* ray->step;
	ray->tex_x = (int)(ray->wall_x * tex->width);
	if ((ray->side == 0 && ray->raydir_x < 0) || (ray->side == 1
			&& ray->raydir_y > 0))
		ray->tex_x = tex->width - ray->tex_x - 1;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (tex->height - 1);
		ray->tex_pos += ray->step;
		put_pixel_to_screen(&data->mlx, x, y, tex->addr[ray->tex_y * tex->width
			+ ray->tex_x]);
		y++;
	}
}

void	fill_floor_and_ceiling(t_data *data)
{
	int	x;
	int	y;

	data->colors.floor = (data->colors.floor_color[0] << 16)
		| (data->colors.floor_color[1] << 8)
		| data->colors.floor_color[2];
	data->colors.ceiling = (data->colors.ceiling_color[0] << 16)
		| (data->colors.ceiling_color[1] << 8)
		| data->colors.ceiling_color[2];
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				data->mlx.addr[y * SCREEN_WIDTH + x] = data->colors.ceiling;
			else
				data->mlx.addr[y * SCREEN_WIDTH + x] = data->colors.floor;
			x++;
		}
		y++;
	}
}

void	draw_wand(t_data *data)
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;
	int	color;

	screen_x = (SCREEN_WIDTH - data->wand.width) / 2;
	screen_y = SCREEN_HEIGHT - data->wand.height;
	y = 0;
	while (y < data->wand.height)
	{
		x = 0;
		while (x < data->wand.width)
		{
			color = data->wand.addr[y * data->wand.width + x];
			if (color != 0xFF00FF && (color & 0xFFFFFF) != 0)
				put_pixel_to_screen(&data->mlx, screen_x + x, screen_y + y,
					color);
			x++;
		}
		y++;
	}
}

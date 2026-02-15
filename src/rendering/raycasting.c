/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:29:07 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 18:10:22 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	compute_ray_direction(t_data *data, int column)
{
	data->ray.camera_x = (2.5 * column / (double)SCREEN_WIDTH) - 1;
	data->ray.raydir_x = data->player.dir_x + (data->player.plane_x
			* data->ray.camera_x);
	data->ray.raydir_y = data->player.dir_y + (data->player.plane_y
			* data->ray.camera_x);
	data->ray.map_x = (int)data->player.x;
	data->ray.map_y = (int)data->player.y;
}

void	raycasting(t_data *data)
{
	int			x;
	t_texture	*tex;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		compute_ray_direction(data, x);
		setup_dda(data);
		perform_dda(&data->ray, data->map.padded_map);
		calculate_line_height(data);
		calculate_wall_hit_position(data);
		tex = select_wall_texture(data);
		draw_wall_slice(data, x, tex);
		x++;
	}
	draw_wand(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.game, data->mlx.img, 0, 0);
}

void	rendering(t_data *data)
{
	raycasting(data);
}

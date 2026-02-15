/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:35:07 by msafa             #+#    #+#             */
/*   Updated: 2026/01/11 19:38:08 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

t_texture	*select_wall_texture(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.raydir_x > 0)
			return (&data->walls.walls[EAST]);
		else
			return (&data->walls.walls[WEST]);
	}
	else
	{
		if (data->ray.raydir_y > 0)
			return (&data->walls.walls[SOUTH]);
		else
			return (&data->walls.walls[NORTH]);
	}
}

void	calculate_wall_hit_position(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_x = data->player.y + (data->ray.perpwall_dist
				* data->ray.raydir_y);
	else
		data->ray.wall_x = data->player.x + (data->ray.perpwall_dist
				* data->ray.raydir_x);
	data->ray.wall_x -= floor(data->ray.wall_x);
}

void	calculate_line_height(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwall_dist = data->ray.sidedist_x - data->ray.deltadist_x;
	else
		data->ray.perpwall_dist = data->ray.sidedist_y - data->ray.deltadist_y;
	if (data->ray.perpwall_dist < 0.0001)
		data->ray.perpwall_dist = 0.0001;
	data->ray.line_height = (int)(SCREEN_HEIGHT / data->ray.perpwall_dist);
	data->ray.draw_start = -(data->ray.line_height) / 2 + SCREEN_HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->ray.draw_end >= SCREEN_HEIGHT)
		data->ray.draw_end = SCREEN_HEIGHT - 1;
}

void	perform_dda(t_ray *ray, char **padded_map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (padded_map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:21:37 by msafa             #+#    #+#             */
/*   Updated: 2026/01/11 17:18:35 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(ROTSPEED) - data->player.dir_y
		* sin(ROTSPEED);
	data->player.dir_y = old_dir_x * sin(ROTSPEED) + data->player.dir_y
		* cos(ROTSPEED);
	data->player.plane_x = data->player.plane_x * cos(ROTSPEED)
		- data->player.plane_y * sin(ROTSPEED);
	data->player.plane_y = old_plane_x * sin(ROTSPEED) + data->player.plane_y
		* cos(ROTSPEED);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-ROTSPEED)
		- data->player.dir_y * sin(-ROTSPEED);
	data->player.dir_y = old_dir_x * sin(-ROTSPEED) + data->player.dir_y
		* cos(-ROTSPEED);
	data->player.plane_x = data->player.plane_x * cos(-ROTSPEED)
		- data->player.plane_y * sin(-ROTSPEED);
	data->player.plane_y = old_plane_x * sin(-ROTSPEED) + data->player.plane_y
		* cos(-ROTSPEED);
}

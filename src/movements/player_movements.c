/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:55:56 by msafa             #+#    #+#             */
/*   Updated: 2026/01/12 19:23:17 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	move_forward(t_data *data)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x + data->player.dir_x * MOVESPEED;
	next_y = data->player.y + data->player.dir_y * MOVESPEED;
	if (data->map.padded_map[(int)data->player.y][(int)next_x] == '0')
		data->player.x = next_x;
	if (data->map.padded_map[(int)next_y][(int)data->player.x] == '0')
		data->player.y = next_y;
}

void	move_backward(t_data *data)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x - data->player.dir_x * MOVESPEED;
	next_y = data->player.y - data->player.dir_y * MOVESPEED;
	if (data->map.padded_map[(int)data->player.y][(int)next_x] == '0')
		data->player.x = next_x;
	if (data->map.padded_map[(int)next_y][(int)data->player.x] == '0')
		data->player.y = next_y;
}

void	move_right(t_data *data)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x + data->player.plane_x * MOVESPEED;
	next_y = data->player.y + data->player.plane_y * MOVESPEED;
	if (data->map.padded_map[(int)data->player.y][(int)next_x] == '0')
		data->player.x = next_x;
	if (data->map.padded_map[(int)next_y][(int)data->player.x] == '0')
		data->player.y = next_y;
}

void	move_left(t_data *data)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x - data->player.plane_x * MOVESPEED;
	next_y = data->player.y - data->player.plane_y * MOVESPEED;
	if (data->map.padded_map[(int)data->player.y][(int)next_x] == '0')
		data->player.x = next_x;
	if (data->map.padded_map[(int)next_y][(int)data->player.x] == '0')
		data->player.y = next_y;
}

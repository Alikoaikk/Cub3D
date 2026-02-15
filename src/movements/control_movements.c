/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:23:15 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 18:31:19 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int	update_frame(t_data *data)
{
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
	if (data->keys.left)
		rotate_left(data);
	if (data->keys.right)
		rotate_right(data);
	fill_floor_and_ceiling(data);
	rendering(data);
	return (0);
}

int	move(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_game(data);
	if (keycode == XK_w)
		data->keys.w = 1;
	if (keycode == XK_s)
		data->keys.s = 1;
	if (keycode == XK_a)
		data->keys.a = 1;
	if (keycode == XK_d)
		data->keys.d = 1;
	if (keycode == XK_Left)
		data->keys.left = 1;
	if (keycode == XK_Right)
		data->keys.right = 1;
	return (0);
}

int	stop(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = 0;
	if (keycode == XK_s)
		data->keys.s = 0;
	if (keycode == XK_a)
		data->keys.a = 0;
	if (keycode == XK_d)
		data->keys.d = 0;
	if (keycode == XK_Left)
		data->keys.left = 0;
	if (keycode == XK_Right)
		data->keys.right = 0;
	return (0);
}

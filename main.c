/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:48:39 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 18:31:15 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/data.h"
#include "includes/libft.h"
#include "includes/mlx.h"

void	parsing_data(t_data *data, t_checker *checker, t_walls *walls,
		char *file)
{
	char	*stash;

	stash = NULL;
	init_checker(checker);
	parse_textures(data, checker, walls, &stash);
	parse_colors(&stash, data, checker);
	parsing_map(data, file);
}

void	open_window(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
	{
		write(2, "Error\nConnection with the graphical system failed\n", 51);
		exit(1);
	}
	data->mlx.game = mlx_new_window(data->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Cub3d");
	if (!data->mlx.game)
	{
		write(2, "Error\nConnection with the graphical system failed\n", 51);
		exit(1);
	}
}

void	init_screen_buffer(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!mlx->img)
		exit(write(2, "Error: Cannot create image\n", 27));
	mlx->addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_checker	checker;

	if (argc != 2)
		return (0);
	file_validation(argv[1], &data);
	parsing_data(&data, &checker, &data.textures, argv[1]);
	open_window(&data);
	if (load_textures(&data.walls, &data.mlx, &data.textures) < 0)
		exit(1);
	if (load_wand(&data.wand, data.mlx.mlx) < 0)
		exit(1);
	init_screen_buffer(&data.mlx);
	init_camera(&data.player);
	ft_memset(&data.keys, 0, sizeof(data.keys));
	ft_memset(&data.ray, 0, sizeof(data.ray));
	rendering(&data);
	mlx_hook(data.mlx.game, KeyPress, KeyPressMask, move, &data);
	mlx_hook(data.mlx.game, KeyRelease, KeyReleaseMask, stop, &data);
	mlx_loop_hook(data.mlx.mlx, update_frame, &data);
	mlx_hook(data.mlx.game, DestroyNotify, NoEventMask, &exit_game, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:26:42 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/09 17:12:01 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	my_close(void)
{
	printf("Doei!\n");
	exit(0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		my_close();
	else if (keycode == 0)
		vars->pos.x--;
	else if (keycode == 2)
		vars->pos.x++;
	else if (keycode == 1)
		vars->pos.y--;
	else if (keycode == 13)
		vars->pos.y++;
	printf("pos(%d, %d)\n", vars->pos.x, vars->pos.y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	fill_game(&game, argc, argv);
	mlx_put_image_to_window(game.mlx, game.win, game.base_map.img, 0, 0);
	mlx_loop(game.mlx);
	// system("leaks main");
}

// int	main(int argc, char **argv)
// {
// 	t_vars		vars;
// 	t_img		img;
// 	t_img		img2;
// 	t_vector	vect;
// 	int			i;
// 	int			j;

// 	vars.size.x = 1000;
// 	vars.size.y = 1000;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, vars.size.x, vars.size.y, \
// 		"My \"first\" window!");
// 	i = 0;
// 	j = 0;
// 	img.img = mlx_new_image(vars.mlx, vars.size.x, vars.size.y);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
// 		&img.line_size, &img.endian);
// 	for (int i = 0; i < vars.size.x; i++)
// 	{
// 		for (int j = 0; j < vars.size.y; j++)
// 			my_pixel_put(&img, i, j, trgb(0, (int)(i / (vars.size.x / 256.0)), \
// 				(int)(j / (vars.size.y / 256.0)), 0));
// 	}
// 	img2 = imgcpy(vars, img);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img2.img, 0, 0);
// 	mlx_hook(vars.win, 17, 1L << 0, my_close, &vars);
// 	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
// 	mlx_loop(vars.mlx);
// }

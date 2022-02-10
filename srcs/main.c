/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:26:42 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 14:03:04 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/ft_printf/ft_printf.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	fill_game(&game, argc, argv);
	mlx_hook(game.win, 17, 1L << 0, my_close, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
}

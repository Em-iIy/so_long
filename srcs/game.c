/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:11:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/24 13:16:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

static void	choose_sprite(t_game *game, int x, int y)
{
	put_sprite(&game->base_map, game->sprites.bg, x, y);
	if (game->map.map[y][x] == '1')
		put_sprite(&game->base_map, game->sprites.wall, x, y);
}

static void	make_base_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	fill_vect(&game->base_map.size, game->size.x, game->size.y);
	game->base_map.img = mlx_new_image(game->mlx, game->size.x, game->size.y);
	game->base_map.addr = mlx_get_data_addr(game->base_map.img, \
		&game->base_map.bits_ppx, &game->base_map.l_size, \
		&game->base_map.endian);
	while (x < game->map.size.x)
	{
		y = 0;
		while (y < game->map.size.y)
		{
			choose_sprite(game, x, y);
			y++;
		}
		x++;
	}
	put_sprite(&game->base_map, game->sprites.exit, game->map.exit_pos.x, \
		game->map.exit_pos.y);
}

static void	make_new_frame(t_game *game)
{
	game->new_frame.img = mlx_new_image(game->mlx, game->size.x, game->size.y);
	game->new_frame.addr = mlx_get_data_addr(game->new_frame.img, \
		&game->new_frame.bits_ppx, &game->new_frame.l_size, \
		&game->new_frame.endian);
}

void	fill_game(t_game *game, int argc, char **argv)
{
	game->map = map_parse(argc, argv);
	game->mlx = mlx_init();
	game->move_count = 0;
	fill_vect(&game->size, game->map.size.x * 32, game->map.size.y * 32);
	fill_vect(&game->p_pos, game->map.start_pos.x, game->map.start_pos.y);
	game->win = mlx_new_window(game->mlx, game->size.x, game->size.y, "solong");
	make_sprites(game);
	make_base_map(game);
	make_new_frame(game);
	put_frame(game, game->map.col_pos, game->p_pos);
}

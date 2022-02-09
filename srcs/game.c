/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:11:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/09 14:01:20 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	fill_game(t_game *game, int argc, char **argv)
{
	game->map = map_parse(argc, argv);
	game->mlx = mlx_init();
	game->move_count = 0;
	fill_vect(&game->size, game->map.size.x * 32, game->map.size.y * 32);
	fill_vect(&game->p_pos, game->map.start_pos.x, game->map.start_pos.y);
	game->win = mlx_new_window(game->mlx, game->size.x, game->size.y, "solong");
	make_sprites(game);
}
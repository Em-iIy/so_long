/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:50:07 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/09 17:06:53 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

static t_img	make_sprite(void *mlx, char *path)
{
	t_img	ret;

	ret.img = mlx_xpm_file_to_image(mlx, path, &ret.size.x, &ret.size.y);
	ret.addr = mlx_get_data_addr(ret.img, &ret.bits_ppx, \
		&ret.l_size, &ret.endian);
	return (ret);
}

void	make_sprites(t_game *game)
{
	game->sprites.bg = make_sprite(game->mlx, "./sprites/bg.xpm");
	game->sprites.wall = make_sprite(game->mlx, "./sprites/wall.xpm");
	game->sprites.col = make_sprite(game->mlx, "./sprites/col.xpm");
	game->sprites.exit = make_sprite(game->mlx, "./sprites/exit.xpm");
}

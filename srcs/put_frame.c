/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:00:00 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 12:25:16 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "so_long.h"

static void	printing(t_game *game, int move_count)
{
	char	*print;
	char	*mcount;

	mcount = ft_itoa(move_count);
	print = ft_strjoin("move: ", mcount);
	ft_printf("%s\n", print);
	mlx_string_put(game->mlx, game->win, 12, 22, trgb(0, 20, 20, 20), print);
	mlx_string_put(game->mlx, game->win, 10, 20, trgb(0, 180, 0, 150), print);
	free(mcount);
	free(print);
}

void	put_frame(t_game *game, t_vector *col_pos, t_vector p_pos)
{
	int	i;

	i = 0;
	put_sprite(&game->new_frame, game->base_map, 0, 0);
	while (col_pos[i].x != -1)
	{
		if (col_pos[i].y != -1)
		{
			put_sprite(&game->new_frame, game->sprites.col, col_pos[i].x, \
				col_pos[i].y);
		}
		i++;
	}
	put_sprite(&game->new_frame, game->sprites.player, p_pos.x, p_pos.y);
	mlx_put_image_to_window(game->mlx, game->win, game->new_frame.img, 0, 0);
	printing(game, game->move_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:36:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 11:28:05 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/ft_printf/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>

static void	win(int move_count)
{
	ft_printf("YOU WIN!\nFinal move count:%d\n", move_count + 1);
	exit(0);
}


static int	check_move(t_map *map, t_vector p_pos, int move_count)
{
	int	i;

	i = 0;
	if (map->map[p_pos.y][p_pos.x] == '1')
		return (0);
	else if (map->map[p_pos.y][p_pos.x] == 'C')
	{
		while (map->col_pos[i].x != -1)
		{
			if (map->col_pos[i].x == p_pos.x && map->col_pos[i].y == p_pos.y)
			{
				map->col_pos[i].y = -1;
				map->col_count--;
				return (1);
			}
			i++;
		}
	}
	else if (map->exit_pos.x == p_pos.x && map->exit_pos.y == p_pos.y)
	{
		if (map->col_count == 0)
			win(move_count++);
	}
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	t_vector	temp_pos;

	temp_pos = game->p_pos;
	if (keycode == ESC_KEY)
		my_close();
	else if (keycode == A_KEY)
		game->p_pos.x--;
	else if (keycode == D_KEY)
		game->p_pos.x++;
	else if (keycode == S_KEY)
		game->p_pos.y++;
	else if (keycode == W_KEY)
		game->p_pos.y--;
	else
		return (0);
	if (!check_move(&game->map, game->p_pos, game->move_count))
	{
		game->p_pos = temp_pos;
		return (0);
	}
	game->move_count++;
	put_frame(game, game->map.col_pos, game->p_pos);
	return (0);
}

int	my_close(void)
{
	ft_printf("Thanks for playing!\n");
	exit(0);
}

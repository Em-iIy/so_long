/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:31:46 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 15:39:35 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static void	set_dimensions(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[0][x])
		x++;
	while (map->map[y])
		y++;
	fill_vect(&map->size, x, y);
}

static void	check_dimensions(t_map *map)
{
	int				i;
	unsigned int	x;

	i = 0;
	x = map->size.x;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != x)
			error_and_exit(INVALID_MAP_SIZE);
		i++;
	}
}

static void	is_wall(char c)
{
	if (c != '1')
		error_and_exit(INVALID_MAP_WALLS);
}

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	set_dimensions(map);
	check_dimensions(map);
	while (i < map->size.x)
	{
		is_wall(map->map[0][i]);
		is_wall(map->map[map->size.y - 1][i]);
		i++;
	}
	i = 0;
	while (i < map->size.y)
	{
		is_wall(map->map[i][0]);
		is_wall(map->map[i][map->size.x - 1]);
		i++;
	}
}

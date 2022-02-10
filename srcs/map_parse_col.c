/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:01:43 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 13:22:09 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void	col_location(t_map *map)
{
	int			i;
	int			j;
	int			k;

	map->col_pos[map->col_count].x = -1;
	i = 0;
	k = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
			{
				fill_vect(&map->col_pos[k], j, i);
				k++;
			}
			j++;
		}
		i++;
	}
}

static void	is_valid(char c)
{
	if (c != 'C' && c != '1' && c != '0' && c != 'P' && c != 'E')
		error_and_exit(INVALID_MAP);
}

void	col_read(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->col_count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->col_count++;
			else
				is_valid(map->map[i][j]);
			j++;
		}
		i++;
	}
	if (map->col_count == 0)
		error_and_exit(INVALID_MAP);
	map->col_pos = (t_vector *)ft_calloc(map->col_count + 1, sizeof(t_vector));
	if (!map->col_pos)
		return ;
	col_location(map);
}

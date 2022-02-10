/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:56:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 11:16:19 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

static char	**map_read(char	*map_path)
{
	int		fd;
	char	**ret_map;
	char	*map;
	char	*temp;

	fd = open(map_path, O_RDONLY);
	map = get_next_line(fd);
	temp = map;
	if (map)
	{
		while (temp)
		{
			temp = get_next_line(fd);
			if (!temp)
				break ;
			map = ft_strjoin(map, temp);
			free(temp);
		}
		ret_map = ft_split(map, '\n');
		free(map);
		close(fd);
	}
	else
		error_and_exit(INVALID_MAP_PATH);
	return (ret_map);
}

t_map	map_parse(int argc, char **argv)
{
	t_map	ret_map;

	if (argc != 2)
		error_and_exit(INVALID_ARGS);
	ret_map.map = map_read(argv[1]);
	check_walls(&ret_map);
	col_read(&ret_map);
	start_location(&ret_map);
	exit_location(&ret_map);
	return (ret_map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:56:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/03/01 17:33:49 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/get_next_line/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

static void	check_ber(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 4)
		error_and_exit(INVALID_MAP_NAME);
	else if (ft_strncmp(&map_path[len - 4], ".ber", 4) != 0)
		error_and_exit(INVALID_MAP_NAME);
}

static char	**map_read(char *map_path)
{
	int		fd;
	char	**ret_map;
	char	*map;
	char	*temp;

	map = NULL;
	fd = open(map_path, O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
		{
			if (!map)
				error_and_exit(INVALID_MAP_PATH);
			break ;
		}
		map = ft_strjoin_free(map, temp);
		free(temp);
	}
	ret_map = ft_split(map, '\n');
	free(map);
	close(fd);
	return (ret_map);
}

t_map	map_parse(int argc, char **argv)
{
	t_map	ret_map;

	if (argc != 2)
		error_and_exit(INVALID_ARGS);
	check_ber(argv[1]);
	ret_map.map = map_read(argv[1]);
	check_walls(&ret_map);
	col_read(&ret_map);
	start_location(&ret_map);
	exit_location(&ret_map);
	return (ret_map);
}

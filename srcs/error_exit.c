/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:42:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 15:41:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/ft_printf/ft_printf.h"
#include <stdlib.h>

void	error_and_exit(int code)
{
	if (code == INVALID_MAP_SIZE)
		ft_printf("Error\nInvalid map size (map is not a rectangle)\n");
	else if (code == INVALID_MAP_PATH)
		ft_printf("Error\nInvalid map path\n");
	else if (code == INVALID_MAP_CONFIG)
		ft_printf("Error\nInvalid map config (illegal char in map)\n");
	else if (code == INVALID_MAP_EXIT)
		ft_printf("Error\nInvalid map config (missing exit)\n");
	else if (code == INVALID_MAP_PLAYER)
		ft_printf("Error\nInvalid map config (missing player)\n");
	else if (code == INVALID_MAP_COL)
		ft_printf("Error\nInvalid map config (missing collectables)\n");
	else if (code == INVALID_MAP_WALLS)
		ft_printf("Error\nInvalid map config (incomplete walls)\n");
	else if (code == INVALID_ARGS)
		ft_printf("Error\nInvalid number of arguments\n");
	exit(1);
}

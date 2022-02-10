/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:42:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/10 14:56:47 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/ft_printf/ft_printf.h"
#include <stdlib.h>

void	error_and_exit(int code)
{
	if (code == INVALID_MAP)
		ft_printf("Error\nInvalid map");
	else if (code == INVALID_MAP_PATH)
		ft_printf("Error\nInvalid map path");
	else if (code == INVALID_ARGS)
		ft_printf("Error\nInvalid number of arguments");
	exit(1);
}

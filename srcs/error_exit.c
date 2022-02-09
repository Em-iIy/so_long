/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:42:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/09 17:50:58 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	error_and_exit(int code)
{
	if (code == INVALID_MAP)
		printf("Error\nInvalid map");
	else if (code == INVALID_MAP_PATH)
		printf("Error\nInvalid map path");
	else if (code == INVALID_ARGS)
		printf("Error\nInvalid number of arguments");
	exit(-1);
}

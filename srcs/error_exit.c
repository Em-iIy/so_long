/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:42:56 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/08 18:04:20 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	error_and_exit(int code)
{
	if (code == 1)
		printf("Invalid map");
	else if (code == 2)
		printf("Invalid map path");
	else if (code == 3)
		printf("Invalid number of arguments");
	exit(-1);
}

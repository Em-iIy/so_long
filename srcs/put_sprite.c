/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:25:26 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/09 17:03:30 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

static int	get_pixel_color(t_img img, int x, int y)
{
	unsigned char	*dst;
	int				offset;

	offset = y * img.l_size + x * (img.bits_ppx / 8);
	dst = img.addr + offset;
	return (trgb(dst[3], dst[2], dst[1], dst[0]));
}

void	put_sprite(t_img *dst, t_img sprite, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < sprite.size.x)
	{
		j = 0;
		while (j < sprite.size.y)
		{
			my_pixel_put(dst, x * 32 + i, y * 32 + j, \
				get_pixel_color(sprite, i, j));
			j++;
		}
		i++;
	}
}

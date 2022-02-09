/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:25:26 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/08 11:31:28 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"

static int	get_pixel_color(t_img img, int x, int y)
{
	unsigned char	*dst;
	int				offset;

	offset = y * img.line_size + x * (img.bits_per_pixel / 8);
	dst = img.addr + offset;
	return (trgb(dst[3], dst[2], dst[1], dst[0]));
}

t_img	imgcpy(t_vars vars, t_img src)
{
	t_img	ret_img;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ret_img.img = mlx_new_image(vars.mlx, vars.size.x, vars.size.y);
	ret_img.addr = mlx_get_data_addr(ret_img.img, &ret_img.bits_per_pixel, \
		&ret_img.line_size, &ret_img.endian);
	while (x < vars.size.x)
	{
		y = 0;
		while (y < vars.size.y)
		{
			my_pixel_put(&ret_img, x, y, get_pixel_color(src, x, y));
			y++;
		}
		x++;
	}
	return (ret_img);
}

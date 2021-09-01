/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:41:44 by chchao            #+#    #+#             */
/*   Updated: 2021/08/31 21:39:09 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
/*Since the bytes are not aligned, the memory offset must always be calculated (using line_length and bits_per_pixel)
- formula exists -> offset = (y * line_length + x * (bits_per_pixel / 8));*/
static void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (color > 0)
		*(unsigned int*)dst = color;
}

static unsigned int	ft_pixel_receive(t_data *data, int x, int y)
{
	return *(unsigned int*)(data->addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8)));
}

void	ft_my_mlx_pixel_put(t_sprite *dst, t_sprite *src, int x, int y)
{
	t_data data_src;
	t_data data_dst;
	int	xx;
	int yy;

	data_src.addr = mlx_get_data_addr(src->img, &data_src.bits_per_pixel,
		&data_src.line_length, &data_src.endian);
	data_dst.addr = mlx_get_data_addr(dst->img, &data_dst.bits_per_pixel,
		&data_dst.line_length, &data_dst.endian);
	yy = 0;
	while (yy < src->height)
	{
		xx = 0;
		while (xx < src->width)
		{
			ft_pixel_put(&data_dst, xx + x, yy + y,
					ft_pixel_receive(&data_src, xx, yy));
			xx++;
		}
		yy++;
	}
}
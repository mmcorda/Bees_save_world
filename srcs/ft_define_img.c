/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:15:30 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 17:47:47 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_define_img(t_window *win)
{
	win->grass.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/grass.xpm",
			&win->grass.width, &win->grass.height);
	win->wall.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/wall.xpm",
			&win->wall.width, &win->wall.height);
	win->flower.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/flower.xpm",
			&win->flower.width, &win->flower.height);
	win->player.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/player.xpm",
			&win->player.width, &win->player.height);
	win->close.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/close.xpm",
			&win->close.width, &win->close.height);
	win->open.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/open.xpm",
			&win->open.width, &win->open.height);
	win->bee.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/bee.xpm",
			&win->bee.width, &win->bee.height);
}

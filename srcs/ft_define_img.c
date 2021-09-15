/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:15:30 by chchao            #+#    #+#             */
/*   Updated: 2021/09/15 19:42:40 by chchao           ###   ########.fr       */
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
	// win->player_down.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/player_down.xpm",
	// 	&win->player_down.width, &win->player_down.height);
	// win->player_right1.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/player_right1.xpm",
	// 	&win->player_right1.width, &win->player_right1.height);
	// win->player_right2.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/player_right2.xpm",
	// 	&win->player_right2.width, &win->player_right2.height);
	// win->player_left1.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/player_left1.xpm",
	// 	&win->player_left1.width, &win->player_left1.height);
	// win->player_left2.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/player_left2.xpm",
		// &win->player_left2.width, &win->player_left2.height);
	win->close_door.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/close_door.xpm",
		&win->close_door.width, &win->close_door.height);
	win->open_door.img = mlx_xpm_file_to_image(win->mlx_ptr, "data/open_door.xpm",
		&win->open_door.width, &win->open_door.height);
}
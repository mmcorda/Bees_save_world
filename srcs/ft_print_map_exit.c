/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:27:07 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 18:50:06 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_print_map_exit(t_window *win, t_check_map var)
{
	if (ft_get_all(win->map))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->grass.img, var.y * 50, var.x * 50);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->open.img, var.y * 50, var.x * 50);
	}
	else
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->grass.img, var.y * 50, var.x * 50);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->close.img, var.y * 50, var.x * 50);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_flower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:38:50 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 18:50:15 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_print_map_flower(t_window *win, t_check_map var)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->grass.img, var.y * 50, var.x * 50);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->flower.img, var.y * 50, var.x * 50);
}

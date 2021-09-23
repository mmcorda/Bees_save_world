/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map_bee.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:43:50 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 18:49:41 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_print_map_bee(t_window *win, t_check_map var)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->player.img, var.y * 50, var.x * 50);
	win->ps.x = var.x * 50;
	win->ps.y = var.y * 50;
}

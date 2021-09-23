/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:01:01 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 18:48:23 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_print_map(t_window *win)
{
	t_check_map	var;

	var.x = 0;
	while (win->map[var.x])
	{
		var.y = 0;
		while (win->map[var.x][var.y])
		{
			if (win->map[var.x][var.y] == '0')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
				win->grass.img, var.y * 50, var.x * 50);
			else if (win->map[var.x][var.y] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
				win->wall.img, var.y * 50, var.x * 50);
			else if (win->map[var.x][var.y] == 'P')
				ft_print_map_bee(win, var);
			else if (win->map[var.x][var.y] == 'C')
				ft_print_map_flower(win, var);
			else if (win->map[var.x][var.y] == 'E')
				ft_print_map_exit(win, var);
			var.y++;
		}
		var.x++;
	}
}

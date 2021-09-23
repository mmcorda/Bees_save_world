/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:04:19 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 15:09:49 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/so_long.h"

void	ft_save_world(t_window *win)
{
	t_check_map	var;

	var.x = 0;
	if (ft_game_over(win))
	{
		while (win->map[var.x])
		{
			var.y = 0;
			while (win->map[var.x][var.y])
			{
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->bee.img, var.y * 50, var.x * 50);
			}
			var.y++;
		}
		var.x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:01:01 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 12:10:20 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/so_long.h"

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
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, var.y * 50, var.x * 50);
			else if (win->map[var.x][var.y] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->wall.img, var.y * 50, var.x * 50);
			else if (win->map[var.x][var.y] == 'P')
			{
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player.img, var.y * 50, var.x * 50);
				win->player_pos.x = var.x * 50;
				win->player_pos.y = var.y * 50;
				// win->player_pos.pos_x = var.x;
				// win->player_pos.pos_y = var.y;
			}
			
			else if (win->map[var.x][var.y] == 'C')
			{
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, var.y * 50, var.x * 50);
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->flower.img, var.y * 50, var.x * 50);
			}
			else if (win->map[var.x][var.y] == 'E')
			{
				if (ft_get_all(win->map))
				{
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, var.y * 50, var.x * 50);
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->open_door.img, var.y * 50, var.x * 50);
				}
				else
				{
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, var.y * 50, var.x * 50);
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->close_door.img, var.y * 50, var.x * 50);
				}
			}
			var.y++;
		}
		var.x++;
	}
}

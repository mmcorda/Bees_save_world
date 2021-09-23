/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:50:05 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 18:20:34 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	g_trace = 1;

void	ft_right(int key, t_window *win)
{
	if (key == 2 && win->map[win->ps.x / 50][(win->ps.y / 50) + 1] != '1' \
			&& win->map[win->ps.x / 50][(win->ps.y / 50) + 1] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->grass.img, win->ps.y, win->ps.x);
		win->map[win->ps.x / 50][(win->ps.y / 50) + 1] = '0';
		{
			win->ps.y += 50;
			printf("%d\n", g_trace++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->player.img, win->ps.y, win->ps.x);
	}
	else if (key == 2 && ft_get_all(win->map)
		&& win->map[win->ps.x / 50][(win->ps.y / 50) + 1] == 'E')
	{
		win->ps.y += 50;
		ft_game_over(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->bee.img, win->ps.y, win->ps.x);
	}
}

void	ft_lift(int key, t_window *win)
{
	if (key == 0 && win->map[win->ps.x / 50][(win->ps.y / 50) - 1] != '1' \
			&& win->map[win->ps.x / 50][(win->ps.y / 50) - 1] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->grass.img, win->ps.y, win->ps.x);
		win->map[win->ps.x / 50][(win->ps.y / 50) - 1] = '0';
		{
			win->ps.y -= 50;
			printf("%d\n", g_trace++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->player.img, win->ps.y, win->ps.x);
	}
	else if (key == 0 && win->map[(win->ps.x / 50)] \
		[(win->ps.y / 50) - 1] == 'E' && ft_get_all(win->map))
	{
		win->ps.y -= 50;
		ft_game_over(win);
	}
}

void	ft_up(int key, t_window *win)
{
	if (key == 13 && win->map[(win->ps.x / 50) - 1][win->ps.y / 50] != '1' \
			&& win->map[(win->ps.x / 50) - 1][win->ps.y / 50] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, \
			win->ps.y, win->ps.x);
		win->map[(win->ps.x / 50) - 1][win->ps.y / 50] = '0';
		{
			win->ps.x -= 50;
			printf("%d\n", g_trace++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->player.img, win->ps.y, win->ps.x);
	}
	else if (key == 13 && win->map[(win->ps.x / 50) - 1] \
		[win->ps.y / 50] == 'E' && ft_get_all(win->map))
	{
		win->ps.y -= 50;
		ft_game_over(win);
	}
}

void	ft_down(int key, t_window *win)
{
	if (key == 1 && win->map[(win->ps.x / 50) + 1][win->ps.y / 50] != '1'
			&& win->map[(win->ps.x / 50) + 1][win->ps.y / 50] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, \
			win->ps.y, win->ps.x);
		win->map[(win->ps.x / 50) + 1][win->ps.y / 50] = '0';
		{
			win->ps.x += 50;
			printf("%d\n", g_trace++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->player.img, win->ps.y, win->ps.x);
	}
	else if (key == 1 && win->map[(win->ps.x / 50) + 1]
		[(win->ps.y / 50) + 1] == 'E' && ft_get_all(win->map))
	{
		win->ps.x += 50;
		ft_game_over(win);
	}
}

void	ft_move(int key, t_window *win)
{
	ft_right(key, win);
	ft_down(key, win);
	ft_up(key, win);
	ft_lift(key, win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:28:50 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 16:44:57 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_game_over(t_window *win)
{	
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->bee.img, 0, 0);
	printf("\e[1;32mCongrats ! You win !\n");
	exit(0);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:28:50 by chchao            #+#    #+#             */
/*   Updated: 2021/09/22 13:34:46 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_game_over(void)
{	
	t_window win;
	
	//mlx_clear_window(win.mlx_ptr, win.win_ptr);
	mlx_destroy_window(win.mlx_ptr, win.win_ptr);
	
	exit(0);
}
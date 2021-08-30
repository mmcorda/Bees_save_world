/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:46:25 by chchao            #+#    #+#             */
/*   Updated: 2021/08/30 19:29:52 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define BUFFER_SIZE 1

#include "../libft/libft.h"
#include <fcntl.h>
#include "mlx.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_check_map
{
	int y;
	int x;
	int k;
	int exit;
	int coltive;
	int player;
}	t_check_map;

typedef struct s_sprite
{
	int		width;
	int		height;
	void	*img;
}	t_sprite;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_check_map	player_pos;
	t_sprite	map_img;
	t_sprite	ground;
	t_sprite	wall;
	t_sprite	fire;
	t_sprite	player_up;
	t_sprite	player_down;
	t_sprite	player_left1;
	t_sprite	player_left2;
	t_sprite	player_right1;
	t_sprite	player_right2;
	t_sprite	close_door;
	t_sprite	open_door;
}	t_window;

int 	get_next_line(int fd, char **line);
int		ft_parsing(t_window *win, char *file);
void	ft_define_img(t_window *win);
int 	deal_key(int key, t_window *win);
int 	get_all(char **map);
void	ft_print_map(t_window *win);

#endif
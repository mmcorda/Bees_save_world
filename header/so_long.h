/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:39:37 by chchao            #+#    #+#             */
/*   Updated: 2021/09/24 12:33:06 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define MAG "\e[0;35m"
# define BBLK "\e[1;30m"

# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_check_map
{
	int	y;
	int	x;
	int	k;
	int	exit;
	int	coltive;
	int	player;
	int	pos_x;
	int	pos_y;
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
	t_check_map	ps;
	t_sprite	map_img;
	t_sprite	grass;
	t_sprite	wall;
	t_sprite	flower;
	t_sprite	player;
	t_sprite	close;
	t_sprite	open;
	t_sprite	bee;
}	t_window;

int		get_next_line(int fd, char **line);
int		ft_parsing(t_window *win, char *file);
void	ft_define_img(t_window *win);
int		deal_key(int key, t_window *win);
int		ft_get_all(char **map);
void	ft_print_map(t_window *win);
void	ft_print_map_exit(t_window *win, t_check_map var);
void	ft_print_map_flower(t_window *win, t_check_map var);
void	ft_print_map_bee(t_window *win, t_check_map var);
void	print_map(char **map);
void	ft_right(int key, t_window *win);
void	ft_lift(int key, t_window *win);
void	ft_up(int key, t_window *win);
void	ft_down(int key, t_window *win);
void	ft_game_over(t_window *win);
void	ft_move(int key, t_window *win);
int		ft_esc(t_window *win);
void	free_line(char *tab);

#endif
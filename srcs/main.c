/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:11:54 by chchao            #+#    #+#             */
/*   Updated: 2021/09/24 12:50:08 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../header/mlx_keycode.h"

static	int	build_height(char *file)
{
	int		fd;
	int		nbr_line;
	char	*line;

	nbr_line = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbr_line++;
		free (line);
	}
	nbr_line++;
	free_line(line);
	close (fd);
	return (nbr_line);
}

static	int	build_width(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_strlen(line);
	free_line(line);
	close (fd);
	return (i);
}

int	deal_key(int key, t_window *win)
{
	if (key == KEY_ECHAP)
		exit(0);
	ft_move(key, win);
	return (0);
}

int	ft_esc(t_window *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	printf("\e[0;35mGame closes up !\n");
	exit (0);
}

int	main(int ac, char **av)
{
	t_window	win;

	if (ac != 2)
	{
		printf("\e[0;35mEeeor ? You mean ./so_long map/basic_map.ber !\n");
		return (0);
	}
	win.mlx_ptr = mlx_init();
	ft_define_img(&win);
	if (ft_parsing(&win, av[1]))
	{
		win.map_img.height = build_height(av[1]) * 50;
		win.map_img.width = build_width(av[1]) * 50;
		win.win_ptr = mlx_new_window(win.mlx_ptr, \
			win.map_img.width, win.map_img.height, "so_long");
		ft_print_map(&win);
		mlx_hook(win.win_ptr, 2, 0, deal_key, &win);
		mlx_hook(win.win_ptr, 17, 0, ft_esc, &win);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}

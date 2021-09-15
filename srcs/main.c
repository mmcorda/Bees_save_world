/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:11:54 by chchao            #+#    #+#             */
/*   Updated: 2021/09/15 16:42:22 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../header/mlx_keycode.h"

static	int	build_height(char *file)
{
	int fd;
	int nbr_line;
	char *line;

	nbr_line = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbr_line++;
		free (line);
	}
	nbr_line++;
	close (fd);
	return (nbr_line);
}

static	int	build_width(char *file)
{
	int fd;
	char *line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_strlen(line);
	free(line);
	close (fd);
	return (i);
}

void	ft_print_map(t_window *win)
{
	t_check_map	var;
	
	var.y = -1;
	while (win->map[++var.y])
	{
		var.x = -1;
		while (win->map[var.y][++var.x])
		{
			if (win->map[var.y][var.x] == '0')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, var.y * 50, var.x * 50);
			else if (win->map[var.y][var.x] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->wall.img, var.y * 50, var.x * 50);
				
			// else if (win->map[var.y][var.x] == 'P')
			// {
			// 	ft_my_mlx_pixel_put(&win->map_img, &win->grass, var.x * 50, var.y * 50);
			// 	ft_my_mlx_pixel_put(&win->map_img, &win->player_right1, var.x * 50, var.y * 50);
			// 	win->player_pos.x = var.x * 50;
			// 	win->player_pos.y = var.y * 50;
			// }
		}
	}
}

int deal_key(int key, t_window *win)
{
	printf("%d\n", key);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player_down.img, 0, 0);
    return (0);
}

int	main(int ac, char **av)
{
	t_window	win;
	
	if (ac != 2)
		return (0);
	win.mlx_ptr = mlx_init();
	ft_define_img(&win);
	if (ft_parsing(&win, av[1]))
	{
		printf ("%d %d\n", build_width(av[1]), build_height(av[1]));
		win.map_img.height = build_height(av[1]) * 50;
		win.map_img.width = build_width(av[1]) * 50;
		if (win.map_img.width < 500 && win.map_img.height < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		else if (win.map_img.width < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, 500, "so_long");
		else if (win.map_img.height < 500)
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, win.map_img.height, "so_long");
		else
			win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "so_long");
		ft_print_map(&win);
		//mlx_hook(win.win_ptr, 2, 1L<<0, deal_key, &win);
		//mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.map_img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:11:54 by chchao            #+#    #+#             */
/*   Updated: 2021/08/30 19:40:54 by chchao           ###   ########.fr       */
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
				mlx_put_image_to_window(&win->map_img, &win->ground, var.x * 50, var.y * 50);
			else if (win->map[var.y][var.x] == '1')
				mlx_put_image_to_window(&win->map_img, &win->wall, var.x * 50, var.y * 50);
			else if (win->map[var.y][var.x] == 'E')
			{
				if (get_all(win->map))
				{
					mlx_put_image_to_window(&win->map_img, &win->ground, var.x * 50, var.y * 50);
					mlx_put_image_to_window(&win->map_img, &win->open_door, var.x * 50, var.y * 50);
				}
				else
				{
					mlx_put_image_to_window(&win->map_img, &win->ground, var.x * 50, var.y * 50);
					mlx_put_image_to_window(&win->map_img, &win->close_door, var.x * 50, var.y * 50);
				}
			}
			else if (win->map[var.y][var.x] == 'C')
			{
				mlx_put_image_to_window(&win->map_img, &win->ground, var.x * 50, var.y * 50);
				mlx_put_image_to_window(&win->map_img, &win->fire, var.x * 50, var.y * 50);
			}
			else if (win->map[var.y][var.x] == 'P')
			{
				mlx_put_image_to_window(&win->map_img, &win->ground, var.x * 50, var.y * 50);
				mlx_put_image_to_window(&win->map_img, &win->player_right1, var.x * 50, var.y * 50);
				win->player_pos.x = var.x * 50;
				win->player_pos.y = var.y * 50;
			}
		}
	}
	var.k = 0;
	while (win->map[var.k])
	{
		printf("%s\n", win->map[var.k]);
		var.k++;
	}
}

int deal_key(int key, t_window *win)
{
	if (key == KEY_ECHAP)
        exit(53);
	if (key == KEY_W)
	{
		if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != 'E')
			win->player_pos.y -= 50;
		else if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 - 1][win->player_pos.x / 50] != '1' && get_all(win->map))
			win->player_pos.y -= 50;
	}
	else if (key == KEY_A)
	{
		if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != 'E')
			win->player_pos.x -= 50;
		else if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 - 1] != '1' && get_all(win->map))
			win->player_pos.x -= 50;
	}
	else if (key == KEY_D)
	{
		if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != 'E')
			win->player_pos.x += 50;
		else if (win->player_pos.x >= 50
			&& win->map[win->player_pos.y / 50][win->player_pos.x / 50 + 1] != '1' && get_all(win->map))
			win->player_pos.x += 50;
	}
	else if (key == KEY_S)
	{
		if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != 'E')
			win->player_pos.y += 50;
		else if (win->player_pos.y >= 50
			&& win->map[win->player_pos.y / 50 + 1][win->player_pos.x / 50] != '1' && get_all(win->map))
			win->player_pos.y += 50;
	}

	if (win->map[win->player_pos.y / 50][win->player_pos.x / 50] == 'C')
		win->map[win->player_pos.y / 50][win->player_pos.x / 50] = '0';
	printf("%d\n", key);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player_down.img, 0, 0);
    return (0);
}

int	main(int ac, char **av)
{
	t_window	win;
	
	if (ac != 2)
		return (0);
	if (ft_parsing(&win, av[1]))
	{
		win.mlx_ptr = mlx_init();
		printf ("%d %d\n", build_width(av[1]), build_height(av[1]));
		win.map_img.height = build_height(av[1]) * 50;
		win.map_img.width = build_width(av[1]) * 50;
	
		win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		win.map_img.img = mlx_new_image(win.mlx_ptr, win.map_img.width, win.map_img.height);
		ft_define_img(&win);
		mlx_hook(win.win_ptr, 2, 1L<<0, deal_key, &win);
	//	mlx_loop_hook(win.win_ptr, )
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
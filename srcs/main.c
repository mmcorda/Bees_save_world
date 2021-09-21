/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:11:54 by chchao            #+#    #+#             */
/*   Updated: 2021/09/21 19:57:59 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../header/mlx_keycode.h"

void	print_map(char **map)
{
	int i;
	
	i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("%c", '\n');
}

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

	var.x = -1;
	while (win->map[++var.x])
	{
		var.y = -1;
		while (win->map[var.x][++var.y])
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
				win->player_pos.pos_x = var.x;
				win->player_pos.pos_y = var.y;
				// printf("POS Y = %d POS X = %d \n", win->player_pos.pos_y, win->player_pos.pos_x);
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
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->close_door.img, var.y * 50, var.x * 50);
				}
				else
				{
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, var.y * 50, var.x * 50);
					mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->close_door.img, var.y * 50, var.x * 50);
				}
			}
		}
	}
}

void	ft_right(int key, t_window *win)
{
	if (key == 2 && win->map[win->player_pos.x / 50][(win->player_pos.y / 50) + 1] != '1' && win->map[win->player_pos.x / 50][(win->player_pos.y / 50) + 1] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, win->player_pos.y, win->player_pos.x);
		win->player_pos.y += 50;
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player.img, win->player_pos.y, win->player_pos.x);
		// printf("%d\n", win->trace++);
		print_map(win->map);
		//printf("in\n%c\n", win->map[win->player_pos.y + 1 / 50][win->player_pos.x / 50]);
		//printf("%c\n", win->map[win->player_pos.y / 50][win->player_pos.x / 50]);
	}
	else if (key == 2 && win->map[win->player_pos.x / 50][(win->player_pos.y / 50) + 1] == 'E' && ft_get_all(win->map))
	{
		//mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->open_door.img, win->player_pos.y, win->player_pos.x);
		win->player_pos.y += 50;
		ft_game_over();
		printf("%s\n", "You Win");
		//ft_game_over();
	}
}

void	ft_down(int key, t_window *win)
{
	if (key == 1 && win->map[(win->player_pos.x / 50) + 1][win->player_pos.y / 50] != '1' && win->map[(win->player_pos.x / 50) + 1][win->player_pos.y / 50] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, win->player_pos.y, win->player_pos.x);
		win->player_pos.x += 50;
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player.img, win->player_pos.y, win->player_pos.x);
		print_map(win->map);
		
	}
	else if (key == 1 && win->map[(win->player_pos.x / 50) + 1][(win->player_pos.y / 50) + 1] == 'E' && ft_get_all(win->map))
	{
		win->player_pos.x += 50;
		ft_game_over();
		printf("%s\n", "You Win");
		//ft_game_over();
	}
}

void	ft_lift(int key, t_window *win)
{
	if (key == 0 && win->map[win->player_pos.x / 50][(win->player_pos.y / 50) - 1] != '1' && win->map[win->player_pos.x / 50][(win->player_pos.y / 50) - 1] != 'E') 
	{ 	
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, win->player_pos.y, win->player_pos.x);
		win->player_pos.y -= 50;
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player.img, win->player_pos.y, win->player_pos.x);
		print_map(win->map);
		//printf("POS Y = %d POS X = %d \n", win->player_pos.y, win->player_pos.x);
		//printf("POS Y = %d POS X = %d \n", win->player_pos.pos_y - 1, win->player_pos.pos_x);
	}
	else if (key == 0 && win->map[(win->player_pos.x / 50)][(win->player_pos.y / 50) - 1] == 'E' && ft_get_all(win->map))
	{
		//mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->open_door.img, win->player_pos.y, win->player_pos.x);
		win->player_pos.y -= 50;
		ft_game_over();
		printf("%s\n", "You Win");
		//ft_game_over();
	}
	
}

void	ft_up(int key, t_window *win)
{
	if (key == 13 && win->map[(win->player_pos.x / 50) - 1][win->player_pos.y / 50] != '1' && win->map[(win->player_pos.x / 50) - 1][win->player_pos.y / 50] != 'E')//W = UP
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->grass.img, win->player_pos.y, win->player_pos.x);
		win->player_pos.x -= 50;
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->player.img, win->player_pos.y, win->player_pos.x);
		print_map(win->map);
		//printf("POS Y = %d POS X = %d \n", win->player_pos.y, win->player_pos.x);
	}
	else if (key == 13 && win->map[(win->player_pos.x / 50) - 1][win->player_pos.y / 50] == 'E' && ft_get_all(win->map))
	{
		win->player_pos.y -= 50;
		ft_game_over();
		printf("%s\n", "You Win");
		//ft_game_over();
	}
	
}

int deal_key(int key, t_window *win, t_check_map var)
{
	(void)var;
	if (key == KEY_ECHAP)
        exit(0);
	ft_right(key, win);
	ft_down(key, win);
	ft_up(key, win);
	ft_lift(key, win);
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
		//printf ("%d %d\n", build_width(av[1]), build_height(av[1]));
		win.map_img.height = build_height(av[1]) * 50;
		win.map_img.width = build_width(av[1]) * 50;
		win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		// if (win.map_img.width < 800 && win.map_img.height < 800)
		// 	win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		// else if (win.map_img.width < 800)
		// 	win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, 800, "so_long");
		// else if (win.map_img.height < 800)
		// 	win.win_ptr = mlx_new_window(win.mlx_ptr, 800, win.map_img.height, "so_long");
		// else
		// 	win.win_ptr = mlx_new_window(win.mlx_ptr, 800, 800, "so_long");
		ft_print_map(&win);
		mlx_hook(win.win_ptr, 2, 0, deal_key, &win);
		// mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.map_img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
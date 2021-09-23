/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 12:11:54 by chchao            #+#    #+#             */
/*   Updated: 2021/09/23 16:48:04 by chchao           ###   ########.fr       */
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

int deal_key(int key, t_window *win)
{
	if (key == KEY_ECHAP)
        exit(0);
	ft_move(key, win);
    return (0);
}

int	ft_esc(t_window *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	printf("\e[0;35mSure ? Game closes up !\n");
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
		win.map_img.height = build_height(av[1]) * 50;
		win.map_img.width = build_width(av[1]) * 50;
		win.win_ptr = mlx_new_window(win.mlx_ptr, win.map_img.width, win.map_img.height, "so_long");
		ft_print_map(&win);
		mlx_hook(win.win_ptr, 2, 0, deal_key, &win);
		mlx_hook(win.win_ptr, 17, 0, ft_esc, &win);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}

// makefile 要藏libimlx.a compile的過程，
// 顯示keycode的指標（我寫錯），

// 超大型地圖人物移動要地圖跟著動
// parsing
// 測試mep.ber(空白欓)要回覆error, 
// .ber檔案裡面只有兩行1111111111要回復錯誤，
// 牆壁如果被Ｐ,Ｅ,Ｃ，取帶要顯是錯誤，
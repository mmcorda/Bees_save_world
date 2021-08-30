/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:54:18 by chchao            #+#    #+#             */
/*   Updated: 2021/08/18 17:20:13 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../header/mlx_keycode.h"

static int ft_search_ch(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
static int	ft_cutline(int index, char *rest, char **line)
{
	int	len;

	*line = ft_substr(rest, 0, index);
	index++;
	len = ft_strlen(rest + index) + 1;
	rest = ft_memmove(rest, rest + index, len);
	return (1);
}
char	*ft_jointfree(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	int		i;
	i = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	free(s1);
	s1 = NULL;
	i = -1;
	while (s2[++i])
		join[i + len1] = s2[i];
	join[i + len1] = '\0';
	return (join);
}

static void ft_clean(char **rest, char **line)
{
	if (rest)
	{
		*line = ft_strdup(*rest);
		free (*rest);
		*rest = NULL;
	}
	else
		*line = ft_strdup("");
}

int get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			lu;
	int			index;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	lu = 1;
	if (rest && ft_search_ch(rest, '\n') != -1)
	{
		index = ft_search_ch(rest, '\n');
		return (ft_cutline(index, rest, line));
	}
	while (lu > 0)
	{
		lu = read (fd, buf, BUFFER_SIZE);
		buf[lu] = '\0';
		rest = ft_jointfree(rest, buf);
		index = ft_search_ch(rest, '\n');
		if (index != -1)
			return (ft_cutline(index, rest, line));
	}
	ft_clean(&rest, line);
	return (0);

}

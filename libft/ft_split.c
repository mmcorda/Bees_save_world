/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:09:31 by mac               #+#    #+#             */
/*   Updated: 2021/04/08 16:37:48 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbw(char const *s, char c)
{
	int	i;
	int	nbw;
	int	len;

	i = 0;
	nbw = 0;
	len = ft_strlen(s);
	while (s[i] == c || s[i] == 0)
		i++;
	while (i <= len)
	{
		if (s[i] == c || s[i] == 0)
		{
			nbw++;
			while (s[i] == c || s[i] == 0)
				i++;
		}
		else
			i++;
	}
	return (nbw);
}

static int	count_lenw(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static int	is_c(const char *s, char c, int i)
{
	if (c == 0)
		return (i);
	while (s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		i;
	int		len;
	int		n;

	if (!s)
		return (0);
	table = malloc(sizeof(char *) * (count_nbw(s, c) + 1));
	if (!table)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			len = count_lenw(&s[i], c);
			table[n++] = ft_substr(s, i, len);
			i = i + len;
		}
		i = is_c(s, c, i);
	}
	table[n] = NULL;
	return (table);
}

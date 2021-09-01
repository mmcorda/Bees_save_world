/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:18:51 by mac               #+#    #+#             */
/*   Updated: 2021/04/08 16:25:15 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	char_in_set(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && char_in_set(s1[end], set))
		end--;
	if (!set || ft_strlen(s1) < ft_strlen(set))
		return (ft_strdup(s1));
	dst = malloc(sizeof(char) * (end - start + 2));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}

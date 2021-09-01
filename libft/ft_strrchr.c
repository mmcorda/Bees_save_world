/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:06:25 by mac               #+#    #+#             */
/*   Updated: 2021/04/05 12:45:32 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*last_occurrence;

	last_occurrence = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			last_occurrence = (char *)&str[i];
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (last_occurrence);
}

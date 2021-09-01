/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:34:20 by mac               #+#    #+#             */
/*   Updated: 2021/04/08 15:03:18 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc (size_t count, size_t size)
{
	void	*str;
	int		mem;

	mem = count * size;
	str = malloc (mem);
	if (!(str))
		return (NULL);
	ft_bzero(str, mem);
	return (str);
}

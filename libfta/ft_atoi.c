/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:44:20 by mac               #+#    #+#             */
/*   Updated: 2021/04/07 18:13:48 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
			return (0);
		else
			res = res * 10 + (str[i++] - 48);
	}
	if (res == 2147483648 && sign == 1)
		return (0);
	res = sign * res;
	return (res);
}

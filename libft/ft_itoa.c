/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchao <chchao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:25:53 by mac               #+#    #+#             */
/*   Updated: 2021/09/23 18:58:34 by chchao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	count_ch(int n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill_positive(char *str, int n)
{
	int	len;

	len = count_ch(n);
	while (len >= 1)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

static char	*fill_negative(char *str, int n)
{
	int	len;

	len = count_ch(n);
	str[0] = '-';
	if (n < 0)
		n = -n;
	while (len > 1)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = count_ch(n);
	str = malloc (sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		fill_negative(str, n);
	else
		fill_positive(str, n);
	str[size] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:44:00 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 15:51:50 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_nums(int n)
{
	int c;

	c = 1;
	while ((n = n / 10))
		c++;
	return (c);
}

static void	calcthis(char *res, int n, int *i)
{
	while (n > 0)
	{
		res[--*i] = 48 + (n % 10);
		n = n / 10;
	}
}

static char	*null_n_min(int n)
{
	char	*res;

	if (n == 0)
	{
		if (!(res = (char *)ft_memalloc(sizeof(char) + 1)))
			return (NULL);
		return (ft_strcpy(res, "0"));
	}
	if (!(res = (char *)ft_memalloc(sizeof(char) + 12)))
		return (NULL);
	return (ft_strcpy(res, "-2147483648"));
}

char		*ft_itoa(int n)
{
	char	*res;
	int		flag;
	int		i;

	if (n == 0 || n == -2147483648)
		res = null_n_min(n);
	else
	{
		res = NULL;
		flag = 0;
		if (n < 0)
		{
			flag = 1;
			n *= -1;
		}
		i = cnt_nums(n) + 1 + flag;
		if (!(res = (char *)ft_memalloc(sizeof(char) * i)))
			return (NULL);
		res[--i - 1] = 0;
		calcthis(res, n, &i);
		if (flag)
			res[--i] = '-';
	}
	return (res);
}

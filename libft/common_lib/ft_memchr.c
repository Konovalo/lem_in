/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:01:05 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 16:21:27 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (NULL);
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (--n <= 0)
			return (NULL);
		if (!(*(unsigned char *)s++))
			break ;
	}
	return ((unsigned char *)s);
}

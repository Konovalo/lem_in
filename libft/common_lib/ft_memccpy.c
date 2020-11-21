/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:59:46 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 12:12:24 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src++;
		if (*(unsigned char *)dest++ == (unsigned char)c)
			return (dest);
	}
	return (NULL);
}

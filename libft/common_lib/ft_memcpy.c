/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:04:34 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 12:11:20 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void *head_s1;

	if (!s1 && !s2)
		return (NULL);
	head_s1 = s1;
	while (n-- > 0)
		*(unsigned char *)s1++ = *(unsigned char *)s2++;
	return (head_s1);
}

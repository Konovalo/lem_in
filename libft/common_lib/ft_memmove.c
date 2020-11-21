/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:06:13 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 15:44:20 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void *buff;

	if (!s1 && !s2)
		return (NULL);
	if (!(buff = malloc(sizeof(char) * n)))
		return (NULL);
	ft_memcpy(buff, s2, n);
	ft_memcpy(s1, buff, n);
	free(buff);
	return (s1);
}

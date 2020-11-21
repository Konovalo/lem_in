/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:04:26 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 17:05:03 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len_s2;

	if (!*s2)
		return ((char *)s1);
	len_s2 = ft_strlen(s2);
	while (*s1 && n-- >= len_s2)
	{
		if (*s1 == *s2 && !ft_memcmp(s1, s2, len_s2))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

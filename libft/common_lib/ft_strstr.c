/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:44:17 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 13:39:25 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*found;
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	found = (char *)s1;
	while (*s1)
	{
		if (!*s2 || \
			((found = ft_strchr(s1, *s2)) && !ft_memcmp(found, s2, len_s2)))
			return (found);
		if (!found)
			break ;
		s1 = ++found;
	}
	if (*s1 == *s2)
		return ((char *)s1);
	return (NULL);
}

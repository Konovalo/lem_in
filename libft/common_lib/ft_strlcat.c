/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:54:29 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 16:55:25 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	result;

	len_s1 = ft_strlen(s1);
	result = ft_strlen(s2);
	if (n == 0)
		return (result);
	if (n < len_s1)
		result += n;
	else
		result += len_s1;
	while (*s1)
		s1++;
	while (*s2 && len_s1++ < n - 1)
		*s1++ = *s2++;
	*s1 = 0;
	return (result);
}

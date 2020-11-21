/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:01:54 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 17:03:15 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*p_s1;
	size_t	len_s2;

	p_s1 = ft_memccpy(s1, s2, 0, n);
	if ((len_s2 = ft_strlen(s2)) < n)
		ft_memset(p_s1, 0, n - len_s2 - 1);
	return (s1);
}

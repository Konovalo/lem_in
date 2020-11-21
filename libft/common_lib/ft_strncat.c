/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:59:15 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 17:01:00 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*head_s1;
	size_t	len_s2;

	head_s1 = s1;
	while (*s1++)
		;
	if ((len_s2 = ft_strlen(s2)) < n)
		n = len_s2;
	ft_memcpy(--s1, s2, n);
	if (s1[n])
		s1[n] = 0;
	return (head_s1);
}

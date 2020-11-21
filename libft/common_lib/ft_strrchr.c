/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:05:17 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 17:59:26 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*head;

	head = (char *)s;
	while (*s)
		s++;
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (s-- == head)
			break ;
	}
	return (NULL);
}

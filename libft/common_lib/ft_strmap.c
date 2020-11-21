/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:56:26 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 16:57:43 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	char	*head;

	if (!s || !f || !(new_s = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	head = new_s;
	while (*s)
		*new_s++ = f(*s++);
	*(++new_s) = 0;
	return (head);
}

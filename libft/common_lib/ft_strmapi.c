/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:57:50 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 16:59:03 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	char			*head;
	unsigned int	i;

	if (!s || !f || !(new_s = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	i = 0;
	head = new_s;
	while (*s)
		*new_s++ = f(i++, *s++);
	*(++new_s) = 0;
	return (head);
}

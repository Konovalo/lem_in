/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:51:06 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 17:11:48 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *res;
	char *head;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	head = res;
	while (*src)
		*res++ = *src++;
	*res = '\0';
	return (head);
}

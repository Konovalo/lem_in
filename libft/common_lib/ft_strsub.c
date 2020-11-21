/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:46:08 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 18:11:11 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub_s;

	if (!s || !(sub_s = ft_strnew(len)))
		return (NULL);
	while (start > 0)
	{
		s++;
		start--;
	}
	return (ft_strncpy(sub_s, s, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:22:05 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/20 16:01:02 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i])
	{
		i++;
	}
	return (arr[i] - arr2[i]);
}

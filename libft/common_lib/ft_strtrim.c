/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:46:32 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/13 17:47:54 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tr_s;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (i < j && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	tr_s = ft_strsub(s + i, 0, j - i + 1);
	return (tr_s);
}

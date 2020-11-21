/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_peek_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:28:46 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:29:13 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ll_peek_n(t_node *list, int n)
{
	int	len;

	if ((len = ft_ll_length(list)) < n || n < 0)
		return (NULL);
	if (n == len)
		return (ft_ll_peek_last(list));
	if (n == 0)
		return (ft_ll_peek_first(list));
	while (n-- > 0)
		list = list->next;
	return ((void *)list->data);
}

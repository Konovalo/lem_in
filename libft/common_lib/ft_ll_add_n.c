/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_add_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:14:39 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:15:17 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_ll_add_n(t_node **list, void *data, int n)
{
	t_node	*node;
	t_node	*proc;
	int		len;

	if ((len = ft_ll_length(*list)) < n || n < 0)
		return (NULL);
	if (n == len)
		return (ft_ll_add_last(list, data));
	if (n == 0)
		return (ft_ll_add_first(list, data));
	node = ft_ll_new_node(data);
	proc = *list;
	while (n-- > 1)
		proc = proc->next;
	node->next = proc->next;
	proc->next->prev = node;
	proc->next = node;
	node->prev = proc;
	return (node);
}

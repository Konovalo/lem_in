/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_add_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:10:16 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:10:50 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_ll_add_last(t_node **list, void *data)
{
	t_node	*node;
	t_node	*proc;

	if (!(node = ft_ll_new_node(data)))
		return (NULL);
	proc = *list;
	if (!*list)
		*list = node;
	else
	{
		while (proc->next)
			proc = proc->next;
		proc->next = node;
		node->prev = proc;
	}
	return (node);
}

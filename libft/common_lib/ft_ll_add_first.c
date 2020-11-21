/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_add_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 09:56:42 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/27 19:29:55 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_ll_add_first(t_node **list, void *data)
{
	t_node	*next;
	t_node	*node;

	if (!(node = ft_ll_new_node(data)))
		return (NULL);
	next = *list;
	*list = node;
	node->next = next;
	if (next)
		next->prev = node;
	return (node);
}

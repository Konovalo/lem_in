/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:12:01 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:00 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_node		*dll_add_n(t_node **list, void *data, int n)
{
	t_node	*node;
	t_node	*proc;
	int		len;

	if ((len = dll_length(*list)) < n || n < 0)
		return (NULL);
	if (n == len)
		return (dll_add_last(list, data));
	if (n == 0)
		return (dll_add_first(list, data));
	node = dll_new_node(data);
	proc = *list;
	while (n-- > 1)
		proc = proc->next;
	node->next = proc->next;
	proc->next->prev = node;
	proc->next = node;
	node->prev = proc;
	return (node);
}

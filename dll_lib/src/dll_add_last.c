/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:11:49 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:17:53 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_node		*dll_add_last(t_node **list, void *data)
{
	t_node	*node;
	t_node	*proc;

	if (!(node = dll_new_node(data)))
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

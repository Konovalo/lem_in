/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:11:27 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:17:47 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "dll.h"

t_node		*dll_add_first(t_node **list, void *data)
{
	t_node	*next;
	t_node	*node;

	if (!(node = dll_new_node(data)))
		return (NULL);
	next = *list;
	*list = node;
	node->next = next;
	if (next)
		next->prev = node;
	return (node);
}

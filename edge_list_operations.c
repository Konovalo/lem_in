/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_list_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:08:24 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 00:34:26 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons_structures.h"

t_node			*edge_list_add_all(t_node **node, t_edge *e)
{
	if (!*node)
		return (*node = ft_ll_new_node(e));
	return (ft_ll_add_first(node, e));
}

t_node			*edge_list_add_first(t_node **node, t_edge *e)
{
	t_node		**w;

	w = node;
	if (*node)
	{
		while (*w)
		{
			if (ft_strcmp(((t_vertex*)((t_edge*)(*w)->data)->vertex[0])->name,\
						((t_vertex*)e->vertex[0])->name) == 0 && \
			((t_vertex*)((t_edge*)(*w)->data)->vertex[0])->k == \
			((t_vertex*)(e->vertex[0]))->k \
			&& ft_strcmp(((t_vertex*)((t_edge*)(*w)->data)->vertex[1])->name,\
				((t_vertex*)e->vertex[1])->name) == 0 && \
			((t_vertex*)((t_edge*)(*w)->data)->vertex[1])->k == \
			((t_vertex*)(e->vertex[1]))->k)
				return (*node);
			w = &((*w)->next);
		}
	}
	return (edge_list_add_all(node, e));
}

t_ant_node		*ft_ll_add_last_an(t_ant_node **list, int k)
{
	t_ant_node	*node;
	t_ant_node	*proc;

	if (!(node = ft_ll_new_node_an(k)))
		return (NULL);
	proc = *list;
	if (!*list)
		*list = node;
	else
	{
		while (proc->next)
			proc = proc->next;
		proc->next = node;
	}
	return (node);
}

t_node			*vertex_list_add_last(t_node **list, t_vertex *v)
{
	if (!*list)
	{
		*list = ft_ll_new_node(v);
		return (*list);
	}
	return (ft_ll_add_last(list, v));
}

t_ant_node		*vertex_list_add_last_an(t_ant_node **list, int a)
{
	if (!*list)
		return (*list = ft_ll_new_node_an(a));
	return (ft_ll_add_last_an(list, a));
}

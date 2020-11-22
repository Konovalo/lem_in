/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:54:00 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 16:23:39 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				edge_get_opp_v1(t_edge *e, t_vertex *v)
{
	if (vertex_cmp(e->vertex[0], v) && ((t_vertex*)e->vertex[0])->k == v->k)
		return (1);
	return (0);
}

void			free_visited_vertex(t_node **list)
{
	while (*list)
	{
		vertex_list_pop(list);
	}
}

void			zap_ant(t_ant_node **ant, int y)
{
	while (y > 0)
	{
		vertex_list_add_last_an(ant, 0);
		y--;
	}
}

void			bfs_add_to_lists(t_node **queue, t_node **visited_vertexes, \
		t_vertex *v)
{
	vertex_list_add_last(queue, v);
	vertex_list_push(visited_vertexes, v);
}

void			bfs_clear_service(t_node **list, t_node **queue)
{
	t_vertex	*curr_vert;

	while (*list)
	{
		curr_vert = (t_vertex *)vertex_list_pop(list);
		curr_vert->visited = 0;
		curr_vert->bfs_level = 0;
	}
	while (*queue)
		vertex_list_pop(queue);
}

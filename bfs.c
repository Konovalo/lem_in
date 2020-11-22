/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:48:36 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 16:23:33 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			bfs2(t_node **found_paths, t_node **visited_vertexes, \
		t_node **queue, t_vertex *sv)
{
	t_vertex	*curr_vert;

	while (ft_ll_peek(*queue))
	{
		curr_vert = vertex_list_get_first(queue);
		if (curr_vert->type == END)
		{
			return_trip(curr_vert, found_paths);
			bfs_clear_service(visited_vertexes, queue);
			bfs_add_to_lists(queue, visited_vertexes, sv);
		}
		else
		{
			iterate_edges(curr_vert, queue, visited_vertexes);
			curr_vert->visited = 1;
		}
	}
}

void			bfs(t_graph *graph, t_node **found_paths)
{
	t_node		*queue;
	t_node		*edges_list;
	t_node		*visited_vertexes;
	t_vertex	*sv;

	queue = NULL;
	visited_vertexes = NULL;
	*found_paths = NULL;
	sv = (t_vertex *)(graph->vertex->data);
	bfs_add_to_lists(&queue, &visited_vertexes, sv);
	sv->bfs_level = 0;
	bfs2(found_paths, &visited_vertexes, &queue, sv);
	free_visited_vertex(&visited_vertexes);
}

void			return_trip2(t_node *curr_edge, t_vertex *v, \
		t_vertex *prev_vert, t_vertex **opp_vert)
{
	int			t;

	t = 0;
	while (curr_edge && t == 0)
	{
		*opp_vert = edge_get_opp_v((t_edge *)curr_edge->data, v);
		if ((((*opp_vert)->bfs_level) + 1 == (v->bfs_level) && \
		vertex_cmp((t_vertex*)((t_edge *)curr_edge->data)->vertex[1], v)))
		{
			if (ft_strcmp(prev_vert->name, \
			((t_vertex*)(((t_edge *)curr_edge->data)->vertex[0]))->name) != 0)
				prev_vert = v;
			edge_reverse((t_edge *)curr_edge->data);
			if (!vertex_cmp_forked(v, *opp_vert))
				((t_edge*)curr_edge->data)->visit_count++;
			t = 1;
		}
		if (t == 0)
			curr_edge = curr_edge->next;
	}
}

void			return_trip(t_vertex *v, t_node **found_paths)
{
	t_node		*curr_edge;
	t_vertex	*opp_vert;
	t_vertex	*prev_vert;
	t_node		*time;
	t_node		*curr_found_path;

	prev_vert = v;
	curr_found_path = NULL;
	while (v->type != START)
	{
		curr_edge = v->i_edges;
		if (!vertex_cmp_forked(v, (t_vertex *)ft_ll_peek(curr_found_path)))
			vertex_list_add_first(&curr_found_path, v);
		return_trip2(curr_edge, v, prev_vert, &opp_vert);
		v = opp_vert;
	}
	vertex_list_add_first(&curr_found_path, v);
	ft_ll_add_first(found_paths, curr_found_path);
}

void			iterate_edges(t_vertex *curr_vert, t_node **queue, \
		t_node **visited_vertexes)
{
	t_vertex	*opp_vert;
	t_node		*edges_list;

	edges_list = curr_vert->i_edges;
	while (edges_list)
	{
		opp_vert = edge_get_opp_v((t_edge *)edges_list->data, curr_vert);
		if (((t_edge *)edges_list->data)->visit_count < 2)
			if (edge_get_opp_v1((t_edge *)edges_list->data, curr_vert) == 1 && \
					!(opp_vert->visited) && !vertex_cmp(opp_vert, curr_vert))
			{
				bfs_add_to_lists(queue, visited_vertexes, opp_vert);
				opp_vert->bfs_level = curr_vert->bfs_level + 1;
			}
		edges_list = edges_list->next;
	}
}

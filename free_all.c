/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:55:05 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 00:01:09 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons_structures.h"

void		free_vertex(t_vertex *vertex)
{
	t_node	*next_edge;
	t_node	*edge;

	edge = vertex->i_edges;
	while (edge)
	{
		next_edge = edge->next;
		free(edge);
		edge = next_edge;
	}
	if (vertex->type == MIDDLE && vertex->k == 0)
		free(vertex->name);
	else if (vertex->type == END || vertex->type == START)
		free(vertex->name);
	free(vertex);
}

void		free_mem(t_node *v_list, t_node *e_list)
{
	t_node	*ver_next;
	t_node	*edge_next;

	while (v_list)
	{
		free_vertex((t_vertex *)v_list->data);
		ver_next = v_list->next;
		free(v_list);
		v_list = ver_next;
	}
	while (e_list)
	{
		edge_next = e_list->next;
		free((t_edge*)e_list->data);
		free(e_list);
		e_list = edge_next;
	}
}

void		free_mem_an(t_ant_node *an)
{
	t_ant_node	*next_an;

	while (an)
	{
		next_an = an->next;
		free(an);
		an = next_an;
	}
}

void		free_paths(t_node *paths)
{
	t_node	*free_paths;
	t_node	*paths_next;
	t_node	*free_paths_next;
	t_node	*curr_found_path;

	while (paths)
	{
		paths_next = paths->next;
		free_paths = (t_node*)paths->data;
		while (free_paths)
		{
			free_paths_next = free_paths->next;
			free(free_paths);
			free_paths = free_paths_next;
		}
		free(paths);
		paths = paths_next;
	}
}

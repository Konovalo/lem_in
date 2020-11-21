/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:15:03 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/21 23:17:23 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons_structures.h"

t_edge			*edge_create(t_vertex *v1, t_vertex *v2)
{
	t_edge		*e;

	e = (t_edge *)malloc(sizeof(t_edge));
	e->vertex[0] = v1;
	e->vertex[1] = v2;
	e->visit_count = 0;
	return (e);
}

void			edge_reverse(t_edge *e)
{
	t_vertex	*tmp;

	tmp = e->vertex[0];
	e->vertex[0] = e->vertex[1];
	e->vertex[1] = tmp;
}

t_vertex		*edge_get_opp_v(t_edge *e, t_vertex *v)
{
	t_vertex	*curr;

	if (!vertex_cmp(curr = e->vertex[0], v) || \
			(vertex_cmp(curr = e->vertex[0], v) == 0 && curr->k != v->k))
		return (curr);
	return (e->vertex[1]);
}

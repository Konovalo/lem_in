/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poisk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 00:01:40 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 00:21:27 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons_structures.h"

int			poisk3(t_node *vrem2, t_node *vrem1)
{
	if ((((t_vertex*)(vrem2)->data)->type != START) && \
		(((t_vertex*)((vrem2)->next->data))->type != END) && \
		(!(vertex_cmp(((t_vertex*)(vrem2)->data), \
		((t_vertex*)((vrem2)->next->data))))) &&  \
		(vertex_cmp2(((t_vertex*)(vrem1)->data), \
		((t_vertex*)((vrem2)->next->data))) && \
		vertex_cmp2(((t_vertex*)((vrem1)->next->data)), \
		((t_vertex*)(vrem2)->data))))
		return (1);
	return (0);
}

void		poisk4(t_node *vrem2, t_node *vrem1)
{
	t_node	*free_vrem1;
	t_node	*free_vrem2;
	t_node	*smena;

	free_vrem1 = vrem1->next;
	free_vrem2 = vrem2->next;
	smena = vrem1->next;
	vrem1->next = vrem2->next->next;
	vrem2->next = smena->next;
	vrem2 = vrem2->next;
	free(free_vrem1);
	free(free_vrem2);
}

void		poisk2(t_node **one, t_node *vrem1)
{
	t_node	**two;
	t_node	*vrem2;

	if ((*one)->next)
	{
		two = &((*one)->next);
		vrem2 = (t_node*)(*two)->data;
		while (vrem2 && vrem2->next)
		{
			if (poisk3(vrem2, vrem1) == 1)
				poisk4(vrem2, vrem1);
			if (vrem2)
				vrem2 = vrem2->next;
		}
	}
}

void		poisk(t_node **paths)
{
	t_node	**one;
	t_node	**two;
	t_node	*smena;
	t_node	*vrem1;
	t_node	*vrem2;

	one = paths;
	while (*one)
	{
		vrem1 = (t_node*)(*one)->data;
		while (vrem1 && vrem1->next)
		{
			if ((((t_vertex*)(vrem1->data))->type != START) && \
					(((t_vertex*)(vrem1->next)->data)->type != END && \
					(!(vertex_cmp(((t_vertex*)(vrem1)->data), \
					((t_vertex*)((vrem1)->next->data)))))))
			{
				poisk2(one, vrem1);
			}
			if (vrem1)
				vrem1 = vrem1->next;
		}
		one = &((*one)->next);
	}
}

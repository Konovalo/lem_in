/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:36:02 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 16:23:19 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ants2(t_node *et1, t_node *e, t_ant_node **ann, t_ant_node **an)
{
	if (et1->next)
		(*an)->ant++;
	else
	{
		if (ft_ll_length((t_node*)et1->data) + (*an)->ant > \
				ft_ll_length((t_node*)e->data) + (*ann)->ant)
			(*ann)->ant++;
		else
			(*an)->ant++;
	}
	(*an) = (*ann);
}

int				yslovee2(t_node *etog1, t_ant_node *an)
{
	if (etog1->next && (ft_ll_length((t_node*)etog1->data) + an->ant) \
				== (ft_ll_length((t_node*)(etog1->next)->data) + an->next->ant))
		return (1);
	return (0);
}

int				yslovee1(t_node *etog1, t_ant_node *an)
{
	if (etog1->next && (ft_ll_length((t_node*)etog1->data) + an->ant) > \
			(ft_ll_length((t_node*)(etog1->next)->data) + an->next->ant))
		return (1);
	return (0);
}

void			ants(t_read *read, t_node *etog, t_ant_node *ann)
{
	t_node		*etog1;
	t_ant_node	*an;

	an = ann;
	etog1 = etog;
	while (read->kol > 0)
	{
		if (yslovee1(etog1, an) == 1)
		{
			an->next->ant++;
			read->kol--;
		}
		else if (yslovee2(etog1, an) == 1)
		{
			etog1 = etog1->next;
			an = an->next;
		}
		else
		{
			ants2(etog1, etog, &ann, &an);
			read->kol--;
			etog1 = etog;
		}
	}
	ann = an;
}

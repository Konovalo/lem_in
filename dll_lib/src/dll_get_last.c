/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:12:28 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:09 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void		*dll_get_last(t_node **list)
{
	void	*data;
	t_node	*proc;

	proc = *list;
	if (!proc)
		return (NULL);
	while (proc->next)
		proc = proc->next;
	data = (void *)proc->data;
	if (proc->prev)
		proc->prev->next = NULL;	
	else
		*list = NULL;
	free(proc);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:12:13 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:04 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void		*dll_get_first(t_node **list)
{
	t_node	*proc;
	void	*data;

	if (!(proc = *list))
		return (NULL);
	data = (void *)proc->data;
	*list = proc->next;
	free(proc);
	if (*list)
		(*list)->prev = NULL;
	return (data);
}

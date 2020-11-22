/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_get_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:12:44 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:16 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void		*dll_get_n(t_node **list, int n)
{
	int		len;
	t_node	*proc;
	t_node	*to_delete;
	void	*data;

	proc = *list;
	if ((len = dll_length(*list)) <= n || n < 0)
		return (NULL);
	if (n == len - 1)
		return (dll_get_last(list));
	if (n == 0)
		return (dll_get_first(list));
	while (n-- > 1)
		proc = proc->next;
	data = (void *)proc->next->data;
	proc->next->next->prev = proc;
	to_delete = proc->next;
	proc->next = proc->next->next;
	free(to_delete);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_get_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:18:55 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/28 20:32:08 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_ll_get_last(t_node **list)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_get_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:18:21 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:18:45 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_ll_get_first(t_node **list)
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

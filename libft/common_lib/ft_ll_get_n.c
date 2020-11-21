/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_get_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:19:24 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:19:47 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_ll_get_n(t_node **list, int n)
{
	int		len;
	t_node	*proc;
	t_node	*to_delete;
	void	*data;

	proc = *list;
	if ((len = ft_ll_length(*list)) <= n || n < 0)
		return (NULL);
	if (n == len - 1)
		return (ft_ll_get_last(list));
	if (n == 0)
		return (ft_ll_get_first(list));
	while (n-- > 1)
		proc = proc->next;
	data = (void *)proc->next->data;
	proc->next->next->prev = proc;
	to_delete = proc->next;
	proc->next = proc->next->next;
	free(to_delete);
	return (data);
}

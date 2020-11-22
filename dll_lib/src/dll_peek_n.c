/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_peek_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:14:25 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:47 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	*dll_peek_n(t_node *list, int n)
{
	int	len;

	if ((len = dll_length(list)) < n || n < 0)
		return (NULL);
	if (n == len)
		return (dll_peek_last(list));
	if (n == 0)
		return (dll_peek_first(list));
	while (n-- > 0)
		list = list->next;
	return ((void *)list->data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_peek_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:14:12 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:41 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	*dll_peek_last(t_node *list)
{
	if (!list)
		return (NULL);
	else
		while (list->next)
			list = list->next;
	return ((void *)list->data);
}

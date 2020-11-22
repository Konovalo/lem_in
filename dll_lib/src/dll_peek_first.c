/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_peek_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:14:01 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:18:38 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	*dll_peek_first(t_node *list)
{
	if (!list)
		return (NULL);
	return ((void *)list->data);
}

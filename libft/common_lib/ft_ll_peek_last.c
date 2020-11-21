/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_peek_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:27:46 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:28:32 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ll_peek_last(t_node *list)
{
	if (!list)
		return (NULL);
	else
		while (list->next)
			list = list->next;
	return ((void *)list->data);
}

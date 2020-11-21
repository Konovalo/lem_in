/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:22:17 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/22 10:23:16 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ll_length(t_node *list)
{
	int	l;

	l = 0;
	while (list)
	{
		list = list->next;
		l++;
	}
	return (l);
}
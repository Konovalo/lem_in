/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:20:58 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 18:29:38 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_iswap(int *n1, int *n2)
{
	if (n1 != n2)
	{
		*n1 ^= *n2;
		*n2 ^= *n1;
		*n1 ^= *n2;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compasc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:21:08 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/12 16:21:12 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_comp_asc(intmax_t n1, intmax_t n2)
{
	if (n1 > n2)
		return (1);
	else if (n1 < n2)
		return (-1);
	return (0);
}

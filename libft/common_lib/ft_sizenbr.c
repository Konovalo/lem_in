/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:14:49 by heantoni          #+#    #+#             */
/*   Updated: 2020/08/30 14:14:51 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizenbr(int nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		n++;
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

int	ft_lsizenbr(long int nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		n++;
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

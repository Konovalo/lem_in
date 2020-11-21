/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:40:10 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 15:40:17 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Обработка и вывод значения модификатора преобразования УКАЗАТЕЛЬ.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи.
*/

char	*put_ptr(size_t n)
{
	g_conv.isint = 1;
	g_conv.prefix = PTR;
	if (n || !g_conv.dotpresent || (g_conv.dotpresent && g_conv.precision))
		if (!put_sizetoa_base(n, 16))
			return (NULL);
	return (g_buff.ptr);
}

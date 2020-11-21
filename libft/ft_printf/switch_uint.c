/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:47:32 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:52:38 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Обработка значения модификатора преобразования ЦЕЛОЕ БЕЗ ЗНАКОМ.
** Функция разбита согласно нормам.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

static char		*switch_uint2(const char *str, uintmax_t val)
{
	if (g_conv.modifier == 0)
		return (put_uitoa_base((unsigned)val,\
		g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 10)
		return (put_uctoa_base((unsigned)val,\
		g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 11)
		return (put_ustoa_base((unsigned)val,\
		g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 20)
		return (put_ultoa_base((unsigned long)val,\
		g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 21)
		return (put_ulltoa_base((unsigned long long)val,\
		g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 30)
		return (put_sizetoa_base((size_t)val,\
		g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 35)
		return (put_uimaxtoa_base(val,\
		g_num_bases[(unsigned)*str]));
	return (g_buff.ptr);
}

char			*switch_uint(const char *str)
{
	uintmax_t	val;

	g_conv.prefix = NULL;
	g_conv.isint = 1;
	if (g_conv.dotpresent)
		g_conv.f_zero = 32;
	if (!(val = va_arg(g_argslist, uintmax_t)))
	{
		if (g_conv.precision)
		{
			g_conv.f_hash = 0;
			if (!g_conv.dotpresent)
				return (zeros_insert(0, -1, 1));
			else if (g_conv.precision > 0)
				return (zeros_insert(0, -1, g_conv.precision));
		}
		return (g_buff.ptr);
	}
	return (switch_uint2(str, val));
}

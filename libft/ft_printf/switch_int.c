/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:47:25 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:52:08 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Обработка значения модификатора преобразования ЦЕЛОЕ СО ЗНАКОМ.
** Функция разбита согласно нормам.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

static char	*switch_int2(const char *str, uintmax_t val)
{
	if (g_conv.modifier == 0)
		return (put_itoa_base((int)val,\
	g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 10)
		return (put_ctoa_base((int)val,\
	g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 11)
		return (put_stoa_base((int)val,\
	g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 20)
		return (put_ltoa_base((long)val,\
	g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 21)
		return (put_lltoa_base((long long)val,\
	g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 30)
		return (put_ssizetoa_base((ssize_t)val,\
	g_num_bases[(unsigned)*str]));
	else if (g_conv.modifier == 35)
		return (put_imaxtoa_base(val,\
	g_num_bases[(unsigned)*str]));
		return (g_buff.ptr);
}

char		*switch_int(const char *str)
{
	intmax_t val;

	g_conv.isint = 1;
	if (g_conv.dotpresent)
		g_conv.f_zero = 32;
	if (!(val = va_arg(g_argslist, intmax_t)))
	{
		if (!g_conv.dotpresent || g_conv.precision < 0)
			return (zeros_insert(0, -1, 1));
		else if (g_conv.precision > 0)
			return (zeros_insert(0, -1, g_conv.precision));
		return (g_buff.ptr);
	}
	return (switch_int2(str, val));
}

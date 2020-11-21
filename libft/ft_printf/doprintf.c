/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:16:49 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 15:20:19 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Функции предназначенные для обработки модификаторов и вызова
** соответсвующего обработчика. Функция doprintf разбита в соответввии
** с нормами. См. так же ft_printf.c
*/

/*
** Вызов обработчика в соответствии с заданным модификатором.
*/

/*
** Функция 2/5.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

char	*doprintf_2(const char *str)
{
	if (*str == '%')
	{
		g_conv.prefix = NULL;
		return (buff_addchar('%', 1));
	}
	if (*str == 'c')
		return (put_char(va_arg(g_argslist, int)));
	else if (*str == 's')
		return (put_str(va_arg(g_argslist, char *)));
	else if (ft_tolower(*str) == 'f')
		return (switch_float());
	else if (*str == 'p')
		return (put_ptr(va_arg(g_argslist, size_t)));
	else if (ft_tolower(*str) == 'e')
		return (switch_exp());
	else if (*str == 'o' || ft_tolower(*str) == 'u' ||\
	ft_tolower(*str) == 'x' || *str == 'b')
		return (switch_uint(str));
	else if (*str == 'i' || *str == 'd')
		return (switch_int(str));
	return (g_buff.ptr);
}

/*
** Добавление префиксов для некоторых типов модификаторов.
** 0 для "o", 0x для "x""X"
*/

void	doprintf_3(const char *str)
{
	if (g_conv.f_hash && *str == 'o' &&\
	*(g_buff.ptr - g_conv.curconv_sbmcnt) != '0')
		g_conv.prefix = ZERO;
	else if (g_conv.f_hash && ft_tolower(*str) == 'x' &&\
	(*(g_buff.ptr - g_conv.curconv_sbmcnt) != '0' || g_conv.curconv_sbmcnt > 1)\
	&& g_conv.precision != 0)
		g_conv.prefix = ft_islower(*str) ? PTR : PTR_UPP;
}

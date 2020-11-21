/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:10:13 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:24:12 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** В этом файле находятся функции инициализации структур необходимых
** для разбора строки.
*/

/*
** Инициализация структуры очередного преобразования.
*/

void	init_conversion(void)
{
	g_conv.f_minus = 0;
	g_conv.f_hash = 0;
	g_conv.f_zero = 32;
	g_conv.width = 0;
	g_conv.precision = 6;
	g_conv.uppercase = 0;
	g_conv.modifier = 0;
	g_conv.dotpresent = 0;
	g_conv.isint = 0;
	g_conv.curconv_sbmcnt = 0;
	g_conv.prefix = NULL;
}

/*
** Инициализация массива оснований систем счисления.
** 88 - X, 98 - b, 100 - d, 105 - i, 111 - o, 117 - u, 120 - x
*/

void	init_numeric_beses(void)
{
	g_num_bases[85] = 10;
	g_num_bases[88] = 16;
	g_num_bases[98] = 2;
	g_num_bases[100] = 10;
	g_num_bases[105] = 10;
	g_num_bases[111] = 8;
	g_num_bases[117] = 10;
	g_num_bases[120] = 16;
}

/*
** Инициализация буфера вывода.
**
** Возврат: ссылка на первый байт инициализированного буфера, NULL - в случае
** ошибки выделения памяти.
*/

char	*init_buff(void)
{
	g_buff.size = sizeof(char) * 128;
	if (!(g_buff.start = ft_strnew(g_buff.size)))
		return (NULL);
	g_buff.ptr = g_buff.start;
	return (g_buff.ptr);
}

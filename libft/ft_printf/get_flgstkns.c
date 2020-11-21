/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flgstkns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:28:27 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:45:56 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Функции необходимые для получения флагов, модификаторов размера
** аргумента, ширины поля и точноти.
*/

/*
** Получение флагов из строки разбора.
**
** Возврат: 0 - если флагов нет, 1 - если есть.
*/

int			get_flags(char flag)
{
	if (flag == '-')
	{
		g_conv.f_minus = 1;
		g_conv.f_zero = 32;
	}
	else if (flag == ' ')
		g_conv.prefix = !g_conv.prefix ? SPACE : g_conv.prefix;
	else if (flag == '+')
	{
		g_conv.prefix = PLUS;
	}
	else if (flag == '#')
		g_conv.f_hash = 1;
	else if (flag == '0')
	{
		if (!g_conv.f_minus)
			g_conv.f_zero = 48;
	}
	else
		return (0);
	return (1);
}

/*
** См. get_tokens(char **);
** Содержательная часть функции 3/3, разбито согласно нормам.
*/

static void	get_tokens3(char **str)
{
	if (**str == 'U')
		g_conv.modifier = g_conv.modifier < 20 ? 20 : g_conv.modifier;
	if (ismodifier(*str) == 208)
		g_conv.modifier = g_conv.modifier < 10 ? 10 : g_conv.modifier;
	else if (ismodifier(*str) == 'h')
		g_conv.modifier = g_conv.modifier < 11 ? 11 : g_conv.modifier;
	else if (ismodifier(*str) == 'l')
		g_conv.modifier = g_conv.modifier < 20 ? 20 : g_conv.modifier;
	else if (ismodifier(*str) == 216)
		g_conv.modifier = g_conv.modifier < 21 ? 21 : g_conv.modifier;
	else if (ismodifier(*str) == 'z')
		g_conv.modifier = g_conv.modifier < 30 ? 30 : g_conv.modifier;
	else if (ismodifier(*str) == 'j')
		g_conv.modifier = g_conv.modifier < 35 ? 35 : g_conv.modifier;
	else if (ismodifier(*str) == 'L')
		g_conv.modifier = g_conv.modifier < 40 ? 40 : g_conv.modifier;
	else
		return ;
	if (g_conv.modifier == 10 || g_conv.modifier == 21)
		*str += 2;
	else if (g_conv.modifier != 0)
		(*str)++;
	if (**str == 'U')
		g_conv.modifier = g_conv.modifier < 20 ? 20 : g_conv.modifier;
}

/*
** См. get_tokens(char **);
** Содержательная часть функции 2/3, разбито согласно нормам.
*/

static void	get_tokens2(char **str)
{
	(*str)++;
	g_conv.precision = 0;
	g_conv.dotpresent = 1;
	if (**str == '*')
	{
		(*str)++;
		g_conv.precision = va_arg(g_argslist, int);
		if (g_conv.precision < 0)
		{
			g_conv.precision = 6;
			g_conv.dotpresent = 0;
		}
	}
	else
		while (ft_isdigit(**str))
			g_conv.precision = g_conv.precision * 10 + *(*str)++ - 48;
}

/*
** Получение модификаторов длины (размер занимаемой области памяти) аругумента,
** ширины поля вывода, точности из строки разбора.
** Содержательная часть функции 1/3, разбито согласно нормам. См. так же
** get_tokens(char **).
*/

void		get_tokens(char **str)
{
	while (get_flags(**str))
		(*str)++;
	if (ft_isdigit(**str))
		g_conv.width = 0;
	while (ft_isdigit(**str))
		g_conv.width = g_conv.width * 10 + *(*str)++ - 48;
	if (**str == '*')
	{
		(*str)++;
		g_conv.width = va_arg(g_argslist, int);
		if (g_conv.width < 0)
		{
			g_conv.width = ft_mathiabs(g_conv.width);
			get_flags('-');
		}
	}
	if (**str == '.')
		get_tokens2(str);
	get_tokens3(str);
	g_conv.uppercase = ft_isupper(**str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:20:39 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 17:07:16 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Пользовательская реализация библиотечной функции printf().
*/

/*
** Добавлкние префикса (0, +, 0x и т.п.) к ранее обработанному
** и находящемуся в буфере значению модификатора.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

static char		*put_prefixes(char *tmp_buff, int substr_size)
{
	if (g_conv.prefix)
	{
		g_conv.width -= ft_strlen(g_conv.prefix);
		if (g_conv.f_zero != 32)
		{
			if (!buff_addstr(g_conv.prefix, ft_strlen(g_conv.prefix)))
				return (NULL);
			g_conv.prefix = NULL;
		}
	}
	if (!g_conv.f_minus)
		if (!buff_addchar(g_conv.f_zero, g_conv.width - substr_size))
			return (NULL);
	if (g_conv.prefix)
		buff_addstr(g_conv.prefix, ft_strlen(g_conv.prefix));
	if (!buff_addstr(tmp_buff, substr_size))
		return (NULL);
	if (g_conv.f_minus)
		if (!buff_addchar((g_conv.f_zero = 32),\
		g_conv.width - substr_size))
			return (NULL);
	return (g_buff.ptr);
}

/*
** Функция 4/5.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

static char		*doprintf_4(const char *str)
{
	char	*tmp_buff;
	int		substr_size;

	substr_size = g_conv.curconv_sbmcnt;
	if ((*str == 's' || *str == 'c') && g_conv.prefix &&\
	(*g_conv.prefix == '+' || *g_conv.prefix == ' ' ||\
	*g_conv.prefix == '#'))
		g_conv.prefix = NULL;
	if (!(tmp_buff = ft_strnew(substr_size)))
		return (NULL);
	g_buff.ptr -= substr_size;
	ft_memcpy(tmp_buff, g_buff.ptr, substr_size);
	if (!put_prefixes(tmp_buff, substr_size))
		return (NULL);
	free(tmp_buff);
	return (g_buff.ptr);
}

/*
** Функция 5/5.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

static char		*doprintf_5(const char *str)
{
	if (!doprintf_2(str))
		return (NULL);
	doprintf_3(str);
	if (g_conv.width || g_conv.prefix)
		if (!doprintf_4(str))
			return (NULL);
	return (g_buff.ptr);
}

/*
** Разбор переданной строки и печать символов.
** Функция 1/5. Разбито согласно нормам.
** Cм. так же остальные функции файле doprintf.c
** Возврат: количество выведенных символов, -1 - в слуае неудачи
** (выделение памяти).
*/

static int		doprintf(const char *str)
{
	while (*str)
	{
		if (*str++ != '%')
		{
			if (!buff_addchar(*(str - 1), 1))
				return (-1);
			continue ;
		}
		init_conversion();
		init_numeric_beses();
		while (1)
		{
			get_tokens((char **)&(str));
			if (!get_flags(*str) && !ismodifier(str) &&
			!isprec_option(*str) && !ft_isdigit(*str))
				break ;
		}
		if (!valid_seq(str))
			continue ;
		if (!doprintf_5(str))
			return (-1);
		str++;
	}
	*(g_buff.ptr) = 0;
	return (g_buff.ptr - g_buff.start);
}

/*
** Печать поданной строки с учётом переданных аргументов. Вывод осуществляется
** в стандартный поток вывода STDOUT_FILENO.
**
** Возврат: количество в напечатанных символов.
*/

int				ft_printf(const char *str, ...)
{
	int		len;

	len = 0;
	g_buff.start = NULL;
	va_start(g_argslist, str);
	if (!init_buff())
		return (0);
	if ((len = doprintf(str)) > 0)
		write(1, g_buff.start, len);
	free(g_buff.start);
	va_end(g_argslist);
	return (len > 0 ? len : 0);
}

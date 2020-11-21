/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:14:48 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:48:37 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Функции предназначенные для операций с буфером.
*/

/*
** Определение размера буфера.
**
** Возврат: результат.
*/

static int	get_buff_sp(void)
{
	return (g_buff.start + g_buff.size - g_buff.ptr - 1);
}

/*
** Изменение размера буфера. Новое значение размера на 1/2 больше
** предыдущего.
**
** Возврат: Указатель на следующий за последним символом байт, NULL в случае
** неудачи выделения памяти.
*/

static char	*buff_resize(void)
{
	char	*tmp;
	size_t	old_str_len;

	old_str_len = g_buff.ptr - g_buff.start;
	if (!(tmp = ft_strnew(g_buff.size * 2)))
		return (NULL);
	ft_memcpy(tmp, g_buff.start, g_buff.size);
	g_buff.ptr = tmp + old_str_len;
	g_buff.size *= 2;
	free(g_buff.start);
	g_buff.start = tmp;
	return (g_buff.ptr);
}

/*
** Добавление строки в буфер. Если строка не помещается в остаток буфера,
** размер буфера увеличивается.
**
** Возврат: указатель на конец буфера, NULL если попытка изменения размера
** буфера окончилась неудачно.
*/

char		*buff_addstr(const char *s, int n)
{
	if (n <= 0)
		return (g_buff.ptr);
	if (get_buff_sp() < n + 1)
	{
		if (!buff_resize())
			return (NULL);
	}
	ft_memcpy(g_buff.ptr, s, n);
	g_conv.curconv_sbmcnt += n;
	return (g_buff.ptr += n);
}

/*
** Добавление символа (одного или нескольких) в буфер. Если символы
** не помещается в остаток буфера,** размер буфера увеличивается.
**
** Возврат: указатель на конец буфера, NULL если попытка изменения размера
** буфера окончилась неудачно.
*/

char		*buff_addchar(char c, int n)
{
	if (n <= 0)
		return (g_buff.ptr);
	while (get_buff_sp() < n)
		if (!buff_resize())
			return (NULL);
	ft_memset(g_buff.ptr, c, n);
	g_conv.curconv_sbmcnt += n;
	return (g_buff.ptr += n);
}

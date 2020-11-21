/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsign_int2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:47:09 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:56:57 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Вывод значения модификатора преобразования ЦЕЛОЕ БЕЗ ЗНАКОМ (часть 1/2)
*/

/*
** Функции для вывода типов unsigned long, long long, size_t, uintmax_t.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи.
*/

char	*put_ultoa_base(unsigned long n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n == 0)
	{
		*--p = DIGS[0];
		g_conv.precision--;
	}
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[n % base + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

char	*put_ulltoa_base(unsigned long long n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n == 0)
	{
		*--p = DIGS[0];
		g_conv.precision--;
	}
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[n % base + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

char	*put_sizetoa_base(size_t n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n == 0)
	{
		*--p = DIGS[0];
		g_conv.precision--;
	}
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[n % base + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

char	*put_uimaxtoa_base(uintmax_t n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n == 0)
	{
		*--p = DIGS[0];
		g_conv.precision--;
	}
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[n % base + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

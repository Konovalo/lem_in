/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:43:40 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:58:03 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Вывод значения модификатора преобразования ЦЕЛОЕ СО ЗНАКОМ (часть 2/2)
*/

/*
** Функции для вывода типов long, long long, ssize_t, intmax_t.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи.
*/

char		*put_ltoa_base(long n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n < 0)
		g_conv.prefix = MINUS;
	else if (n == 0)
		*--p = DIGS[0];
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[ft_mathllabs(n % base) + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

char		*put_lltoa_base(long long n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n < 0)
		g_conv.prefix = MINUS;
	else if (n == 0)
		*--p = DIGS[0];
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[ft_mathllabs(n % base) + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

char		*put_ssizetoa_base(ssize_t n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n < 0)
		g_conv.prefix = MINUS;
	else if (n == 0)
		*--p = DIGS[0];
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[ft_mathllabs(n % base) + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

char		*put_imaxtoa_base(intmax_t n, int base)
{
	char	num_buff[MAX_NUM_BUFF_SIZE];
	char	*p;

	num_buff[MAX_NUM_BUFF_SIZE - 1] = 0;
	p = &num_buff[MAX_NUM_BUFF_SIZE - 1];
	if (n < 0)
		g_conv.prefix = MINUS;
	else if (n == 0)
		*--p = DIGS[0];
	zeros_insert(n, base, 0);
	while (n != 0)
	{
		*--p = DIGS[ft_mathllabs(n % base) + 16 * g_conv.uppercase];
		n /= base;
	}
	return (buff_addstr(p, &num_buff[MAX_NUM_BUFF_SIZE - 1] - p));
}

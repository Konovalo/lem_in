/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:40:26 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:51:16 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Вывод значения модификатора преобразования ЦЕЛОЕ СО ЗНАКОМ (часть 1/2)
*/

/*
** Функции для вывода типов char, short, int.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи.
*/

char		*put_ctoa_base(char n, int base)
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

char		*put_stoa_base(short n, int base)
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

char		*put_itoa_base(int n, int base)
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

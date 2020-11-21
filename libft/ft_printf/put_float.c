/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:37:08 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 17:01:03 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Вывод значения модификатора преобразования ЧИСЛО С ПЛАВАЮЩЕЙ ТОЧКОЙ.
*/

/*
** Квадрат числа (long double)
**
** Возврат: результат.
*/

static long double	powdouble(long double n, int p)
{
	long double base;

	base = n;
	if (!p)
		return (1);
	while (--p > 0)
		n *= base;
	return (n);
}

/*
** Округление денормализованного числа.
*/

static void			magic_denorm_nums_maker(void)
{
	int i;
	int overf;

	i = 1;
	overf = 0;
	if (*(g_buff.ptr - i) - 48 >= 5)
	{
		while (1)
		{
			if (!overf && *(g_buff.ptr - i) - 48 < 5)
				break ;
			else if (*(g_buff.ptr - i - 1) - 48 < 9)
			{
				*(g_buff.ptr - i - 1) += 1;
				break ;
			}
			*(g_buff.ptr - i++ - 1) = '0';
			overf = 1;
		}
	}
	g_buff.ptr--;
	*g_buff.ptr = 0;
}

/*
** Запись числа в буфер.
**
** Возвра: ссылка на конец буфера, NULL в случае неудачи записи.
*/

static char			*lets_parce_some_digits(long double n,
					int minus_flag, int epsilon)
{
	n *= minus_flag;
	while (g_conv.precision-- > epsilon)
		if (!buff_addchar(48 + (char)(n = (n - (long long)n) * 10), 1))
			return (NULL);
	if (epsilon)
		magic_denorm_nums_maker();
	return (g_buff.ptr);
}

/*
** Запись числа в буфер. См. так же предыдущие функции.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи.
*/

char				*put_ldtoa(long double n)
{
	long double	dlt;
	int			minus_flag;
	int			res;
	int			epsilon;

	if ((res = check_spec_val(n)))
	{
		if (res == 1)
			return (g_buff.ptr);
		return (NULL);
	}
	minus_flag = n < 0 ? -1 : 1;
	if (n < 0)
		g_conv.prefix = MINUS;
	dlt = 5 / powdouble(10.0, g_conv.precision + 1);
	epsilon = dlt < LDBL_EPSILON ? -1 : 0;
	n += n == 0 ? 0 : dlt * minus_flag;
	put_lltoa_base((long long)n, 10);
	if (g_conv.f_hash || g_conv.precision)
		if (!buff_addchar('.', 1))
			return (NULL);
	if (g_conv.precision)
		lets_parce_some_digits(n, minus_flag, epsilon);
	return (g_buff.ptr);
}

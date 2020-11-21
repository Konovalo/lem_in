/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:36:03 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:07:50 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Вывод значения модификатора преобразования ЭКПОНЕНТА.
*/

/*
** Определение показателя степени.
**
** Возврат: знак представления.
*/

char	get_ldexp(long double *n, int *exp)
{
	*exp = 0;
	while (ft_mathldabs(*n) < 1 && *n != 0)
	{
		*n *= 10;
		(*exp)--;
	}
	while (ft_mathldabs(*n) >= 10)
	{
		*n /= 10;
		(*exp)++;
	}
	return (*exp < 0 ? '-' : '+');
}

/*
** Запись модификатора в буфер.
**
** Возврат: ссылка на буфер, NULL в случае неудачи записи в буфер.
*/

char	*put_ldexp(long double n)
{
	int		exp;
	char	exp_sign;
	int		res;

	if ((res = check_spec_val(n)))
	{
		if (res == 1)
			return (g_buff.ptr);
		return (NULL);
	}
	exp_sign = get_ldexp(&n, &exp);
	if (!put_ldtoa(n) || !buff_addchar(g_conv.uppercase ? 'E' : 'e', 1) ||\
	!buff_addchar(exp_sign, 1))
		return (NULL);
	if (exp < 10 && exp > -10)
		if (!buff_addchar('0', 1))
			return (NULL);
	if (!put_uitoa_base(ft_mathiabs(exp), 10))
		return (NULL);
	return (g_buff.ptr);
}

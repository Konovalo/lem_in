/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:47:40 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 16:52:57 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Утилитарные функции необходимые для работы программы.
*/

/*
** Проверка числа с плавающей точкой на специальные значения (inf, nan, -0)
**
** Возврат: 0 - если на вход функции подано обычное число,
** 1 - в случае, если на если поданное значение оказалось специальным,
** 2 - если выделение памяти для записи в буфер оказалось неудачным.
*/

int		check_spec_val(long double n)
{
	char	*s;

	if (n != 0 && (n * 2) == n)
	{
		if (n < 0)
			g_conv.prefix = MINUS;
		s = g_conv.uppercase ? "INF" : "inf";
	}
	else if (n != n)
		s = g_conv.uppercase ? "NAN" : "nan";
	else
	{
		if (n == 0 && 1 / n < 0)
			g_conv.prefix = MINUS;
		return (0);
	}
	g_conv.f_zero = 32;
	if (!buff_addstr(s, 3))
		return (2);
	return (1);
}

/*
** Вставка необходимого количества нулей перед значением модификатора,
** в случае наличия соответствующих флагов.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи в буфер.
*/

char	*zeros_insert(long long n, int base, int len_if_null)
{
	int	len;

	if (base < 0)
	{
		if (!buff_addchar('0', len_if_null))
			return (NULL);
	}
	else if (g_conv.dotpresent && g_conv.isint &&\
	(len = g_conv.precision - number_len(n, base)) > 0)
	{
		if (!buff_addchar('0', len))
			return (NULL);
	}
	return (g_buff.ptr);
}

/*
** Определение длины числа (количества цифр).
**
** Возврат: результат.
*/

int		number_len(long long n, int base)
{
	int	len;

	len = 0;
	if (!n)
		return (0);
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

/*
** Определение, является ли поданный символ разделителем точности или
** определителем значения ширины и точности считываемого из аргументов.
**
** Возврат: 0 - если символ не является специальным, число - ascii код
** специального символа.
*/

int		isprec_option(char c)
{
	if (c == '.' || c == '*')
		return (c);
	return (0);
}

/*
** Определение, является ли поданный символ модификатором размера.
**
** Возврат: 0 - если символ не является специальным, число - ascii код
** специального символа.
*/

int		ismodifier(const char *s)
{
	if (!ft_strncmp(s, "hh", 2) || !ft_strncmp(s, "ll", 2))
		return (s[0] + s[1]);
	else if (*s == 'h' || *s == 'l' ||\
	*s == 'j' || *s == 'z' || *s == 'L')
		return (*s);
	return (0);
}
